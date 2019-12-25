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
		Texture2D[] trees;
		Texture2D[] candy;
		RenderTarget2D renderTarget;

		const int size = 16;
		const int most = 12;
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
			int y = 1;
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
			image = Content.Load<Texture2D>("sprites02_" + name);
			trees = new Texture2D[2];
			trees[0] = Content.Load<Texture2D>("tree_avoid");
			trees[1] = Content.Load<Texture2D>("tree_death");

			const int max = 13;
			candy = new Texture2D[max];
			for (int idx = 0; idx < max; idx++)
			{
				var file = (idx + 2).ToString().PadLeft(2, '0');
				var text = $"Candy/Candy{file}";
				candy[idx] = Content.Load<Texture2D>(text);
			}

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

				Draw4();
				base.Draw(gameTime);

				GraphicsDevice.SetRenderTarget(null);
				Texture2D resolvedTexture = (Texture2D)renderTarget;

				var xx = scale * size;
				var yy = index.ToString().PadLeft(2, '0');
				//var yy = (index + 2).ToString().PadLeft(2, '0');
				var file = $"Scale{xx}_Index{yy}.bmp";
				//var file = $"Candy{yy}.bmp";
				Stream stream = File.Create("Images/" + file);

				resolvedTexture.SaveAsPng(stream, wide, high);
				Exit();
			}
			else
			{
				Draw4();
				base.Draw(gameTime);
			}
		}

		private void Draw()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			Texture2D source = candy[index];

			Rectangle outset = new Rectangle(0, 0, 4, 4);
			Rectangle middle = new Rectangle(8, 8, 8, 8);

			spriteBatch.Draw(source, new Vector2(4, 4), middle, Color.White);
			spriteBatch.Draw(source, new Vector2(2, 2), outset, Color.White);
			spriteBatch.Draw(source, new Vector2(10, 10), outset, Color.White);

			spriteBatch.End();
		}

		private void Draw2()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			int x = 0;
			int y = 0;
			for (int i = 0; i < most; i++)
			{
				int j = 4 + i;
				y = i * (int)(size * scale);
				var pos = new Vector2(x, y);
				Rectangle dest = GetRectangle(j);
				spriteBatch.Draw(image, pos, dest, Color.White);
			}

			int z = y;
			for(int i = 0; i < 4; i++)
			{
				z = y + (i + 1) * (int)(size * scale);
				var pos = new Vector2(x, z);
				Rectangle dest = GetRectangle(i);
				spriteBatch.Draw(image, pos, dest, Color.White);
			}

			spriteBatch.End();
		}

		private void Draw3()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			int[] arr = { 4, 5, 8, 9, 12, 13, 6, 7, 10, 11, 14, 15, 0, 1, 2, 3 };
			//int[] arr = { 4 };
			int x = 0;
			int y = 0;

			for(int j = 0; j < arr.Length; j++)
			{
				int i = arr[j];
				y = j * (int)(size * scale);
				var pos = new Vector2(x, y);
				Rectangle dest = GetRectangle(i);
				spriteBatch.Draw(image, pos, dest, Color.White);
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

		private void Draw5()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			spriteBatch.Draw(trees[0], Vector2.Zero, Color.White);
			spriteBatch.Draw(trees[1], Vector2.Zero, Color.White);

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