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
		Texture2D font;
		Texture2D[] bonus;
		Texture2D[] bonus02;
		Texture2D[] candy;
		Texture2D[] trees;
		RenderTarget2D renderTarget;

		const int size = 16;
		const int most = 12;
		int index = 0;
		float scale = 1.0f;
		bool saves = false;

		int wide;
		int high;

		public AnGame()
		{
			if(null != ConfigurationManager.AppSettings["saves"])
			{
				saves = Convert.ToBoolean(ConfigurationManager.AppSettings["saves"]);
			}

			//int y = twice ? 2 : 1;
			//int y = most + 4;
			int y = 4;
			wide = 128;// (int)(size * scale);
			high = 512 - 16 * 10;// (int)(y * size * scale);

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

			font = Content.Load<Texture2D>("font_tiles");
			var names = new string[] { "BlueSpiral", "CoolTriangle", "LoveHeart", "PawPrint" };
			const int bns = 4;
			bonus = new Texture2D[bns];
			bonus02 = new Texture2D[bns];
			for (int idx = 0; idx < bns; idx++)
			{
				var name = names[idx];
				bonus[idx] = Content.Load<Texture2D>("Bonus/" + name);
				bonus02[idx] = Content.Load<Texture2D>("Bonus02/" + name);
			}

			const int max = 14;
			candy = new Texture2D[max];
			for (int idx = 0; idx < max; idx++)
			{
				var file = (idx + 2).ToString().PadLeft(2, '0');
				var text = $"Candy/Candy{file}";
				candy[idx] = Content.Load<Texture2D>(text);
			}

			trees = new Texture2D[2];
			trees[0] = Content.Load<Texture2D>("Trees/tree_avoid");
			trees[1] = Content.Load<Texture2D>("Trees/tree_death");


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

				Draw();
				base.Draw(gameTime);

				GraphicsDevice.SetRenderTarget(null);
				Texture2D resolvedTexture = (Texture2D)renderTarget;

				var file = $"Tiles.bmp";
				//var file = $"Candy{yy}.bmp";
				Stream stream = File.Create("Images/" + file);

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

			spriteBatch.Draw(font, Vector2.Zero, Color.White);

			spriteBatch.Draw(trees[0], new Vector2(0, 32), Color.White);
			spriteBatch.Draw(trees[1], new Vector2(0, 48), Color.White);

			for (int idx = 0; idx < bonus.Length; idx++)
			{
				//var image = bonus[idx];
				var image = bonus02[idx];
				var pos = new Vector2(0, 64 + idx * size);
				spriteBatch.Draw(image, pos, Color.White);
			}

			//candy
			for (int idx = 0; idx < candy.Length; idx++)
			{
				var image = candy[idx];
				var pos = new Vector2(0, 128 + idx * size);
				spriteBatch.Draw(image, pos, Color.White);
			}

			spriteBatch.End();
		}
	}
}