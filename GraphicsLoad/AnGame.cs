using System;
using System.Configuration;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using System.IO;

namespace GraphicsLoad
{
	/// <summary>
	/// This is the main type for your game.
	/// </summary>
	public class AnGame : Game
	{
		GraphicsDeviceManager graphics;
		SpriteBatch spriteBatch;
		Texture2D image;
		RenderTarget2D renderTarget;

		const int size = 16;
		int index = 0;
		float scale = 1.0f;
		bool saves = false;
		bool twice = false;

		int wide;
		int high;

		public AnGame()
		{
			if (null != ConfigurationManager.AppSettings["index"])
			{
				index = Convert.ToInt32(ConfigurationManager.AppSettings["index"]);
			}
			if (null != ConfigurationManager.AppSettings["scale"])
			{
				scale = Convert.ToSingle(ConfigurationManager.AppSettings["scale"]);
			}
			if (null != ConfigurationManager.AppSettings["saves"])
			{
				saves = Convert.ToBoolean(ConfigurationManager.AppSettings["saves"]);
			}
			if (null != ConfigurationManager.AppSettings["twice"])
			{
				twice = Convert.ToBoolean(ConfigurationManager.AppSettings["twice"]);
			}

			int y = twice ? 2 : 1;
			wide = (int)(size * scale);
			high = (int)(y * size * scale);

			graphics = new GraphicsDeviceManager(this);
			graphics.PreferredBackBufferWidth = wide;
			graphics.PreferredBackBufferHeight = high;
			Content.RootDirectory = "Content";
		}

		/// <summary>
		/// Allows the game to perform any initialization it needs to before starting to run.
		/// This is where it can query for any required services and load any non-graphic
		/// related content.  Calling base.Initialize will enumerate through any components
		/// and initialize them as well.
		/// </summary>
		protected override void Initialize()
		{
			IsMouseVisible = true;
			base.Initialize();
		}


		/// <summary>
		/// LoadContent will be called once per game and is the place to load
		/// all of your content.
		/// </summary>
		protected override void LoadContent()
		{
			// Create a new SpriteBatch, which can be used to draw textures.
			spriteBatch = new SpriteBatch(GraphicsDevice);
			var name = scale * size;
			image = Content.Load<Texture2D>("sprites" + name);

			PresentationParameters pp = GraphicsDevice.PresentationParameters;
			wide = pp.BackBufferWidth;
			high = pp.BackBufferHeight;
			renderTarget = new RenderTarget2D(GraphicsDevice, wide, high, false, SurfaceFormat.Color, DepthFormat.Depth24);
		}

		/// <summary>
		/// UnloadContent will be called once per game and is the place to unload
		/// game-specific content.
		/// </summary>
		protected override void UnloadContent()
		{
			Content.Unload();
		}

		/// <summary>
		/// Allows the game to run logic such as updating the world,
		/// checking for collisions, gathering input, and playing audio.
		/// </summary>
		/// <param name="gameTime">Provides a snapshot of timing values.</param>
		protected override void Update(GameTime gameTime)
		{
			if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed || Keyboard.GetState().IsKeyDown(Keys.Escape))
			{
				Exit();
			}

			base.Update(gameTime);
		}

		/// <summary>
		/// This is called when the game should draw itself.
		/// </summary>
		/// <param name="gameTime">Provides a snapshot of timing values.</param>
		protected override void Draw(GameTime gameTime)
		{
			if (saves)
			{
				GraphicsDevice.SetRenderTarget(renderTarget);
				GraphicsDevice.Clear(ClearOptions.Target | ClearOptions.DepthBuffer, Color.CornflowerBlue, 1, 0);

				Draw();
				base.Draw(gameTime);

				GraphicsDevice.SetRenderTarget(null);
				Texture2D resolvedTexture = (Texture2D)renderTarget;

				var xx = scale * size;
				var yy = index.ToString().PadLeft(2, '0');
				var file = $"Scale{xx}_Index{yy}.bmp";
				Stream stream = File.Create(file);

				resolvedTexture.SaveAsPng(stream, wide, high);
				Exit();
			}
			else
			{
				Draw();
				base.Draw(gameTime);
			}
		}

		private void Draw()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			Rectangle dest = GetRectangle(index);
			//spriteBatch.Draw(image, new Vector2(0, 0), dest, Color.White, 0.0f, Vector2.Zero, scale, SpriteEffects.None, 1.0f);
			spriteBatch.Draw(image, new Vector2(0, 0), dest, Color.White);

			if (twice)
			{
				dest = GetRectangle(index + 1);
				//spriteBatch.Draw(image, new Vector2(0, size * scale), dest, Color.White, 0.0f, Vector2.Zero, scale, SpriteEffects.None, 1.0f);
				spriteBatch.Draw(image, new Vector2(0, size * scale), dest, Color.White);
			}

			spriteBatch.End();
		}

		private Rectangle GetRectangle(int index)
		{
			int h = index / 4;
			int w = index % 4;
			int delta = (int)(size * scale);
			Rectangle dest = new Rectangle(w * delta, h * delta, delta, delta);
			return dest;
		}
	}
}
