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
		Texture2D image, image02;
		Texture2D[] boss32;
		Texture2D[] boss64;
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
			if(null != ConfigurationManager.AppSettings["index"])
			{
				index = Convert.ToInt32(ConfigurationManager.AppSettings["index"]);
			}
			if(null != ConfigurationManager.AppSettings["scale"])
			{
				scale = Convert.ToSingle(ConfigurationManager.AppSettings["scale"]);
			}
			if(null != ConfigurationManager.AppSettings["saves"])
			{
				saves = Convert.ToBoolean(ConfigurationManager.AppSettings["saves"]);
			}
			if(null != ConfigurationManager.AppSettings["twice"])
			{
				twice = Convert.ToBoolean(ConfigurationManager.AppSettings["twice"]);
			}

			//int y = twice ? 2 : 1;
			//int y = most + 4;
			int y = 16;
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
			image = Content.Load<Texture2D>("sprites");
			image02 = Content.Load<Texture2D>("sprites02");

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
			if(GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed || Keyboard.GetState().IsKeyDown(Keys.Escape))
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
			if(saves)
			{
				GraphicsDevice.SetRenderTarget(renderTarget);
				GraphicsDevice.Clear(ClearOptions.Target | ClearOptions.DepthBuffer, Color.CornflowerBlue, 1, 0);

				Draw3();
				base.Draw(gameTime);

				GraphicsDevice.SetRenderTarget(null);
				Texture2D resolvedTexture = (Texture2D)renderTarget;

				//var xx = scale * size;
				//var yy = index.ToString().PadLeft(2, '0');
				//var yy = (index + 2).ToString().PadLeft(2, '0');
				var file = $"spritemap.bmp";
				//var file = $"Candy{yy}.bmp";
				Stream stream = File.Create("Images/" + file);

				resolvedTexture.SaveAsPng(stream, wide, high);
				Exit();
			}
			else
			{
				Draw3();
				base.Draw(gameTime);
			}
		}

		private void Draw()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			spriteBatch.End();
		}

		//private void Draw2()
		//{
		//	GraphicsDevice.Clear(Color.Black);
		//	spriteBatch.Begin();

		//	int x = 0;
		//	int y = 0;
		//	for (int i = 0; i < most; i++)
		//	{
		//		int j = 4 + i;
		//		y = i * (int)(size * scale);
		//		var pos = new Vector2(x, y);
		//		Rectangle dest = GetRectangle(j);
		//		spriteBatch.Draw(image, pos, dest, Color.White);
		//	}

		//	int z = y;
		//	for(int i = 0; i < 4; i++)
		//	{
		//		z = y + (i + 1) * (int)(size * scale);
		//		var pos = new Vector2(x, z);
		//		Rectangle dest = GetRectangle(i);
		//		spriteBatch.Draw(image, pos, dest, Color.White);
		//	}

		//	spriteBatch.End();
		//}

		private void Draw3()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			int[] arr = { 4, 5, 8, 9, 12, 13, 6, 7, 10, 11, 14, 15, 0, 1, 2, 3 };
			//int[] arr = { 4 };
			int x = 0;
			int y = 0;

			Texture2D draws = image;
			for(int j = 0; j < arr.Length; j++)
			{
				draws = image;
				int i = arr[j];
				if (6 == i)
				{
					i = 4;
					draws = image02;
				}
				if (7 == i)
				{
					i = 5;
					draws = image02;
				}
				y = j * (int)(size * scale);
				var pos = new Vector2(x, y);
				Rectangle dest = GetRectangle(i);
				spriteBatch.Draw(draws, pos, dest, Color.White);
			}

			spriteBatch.End();
		}

		private void Draw4()
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