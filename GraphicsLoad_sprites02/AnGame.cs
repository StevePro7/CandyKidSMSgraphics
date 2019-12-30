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
		Texture2D image01, image02;
		Texture2D[] data16;
		Texture2D[] boss24;
		Texture2D[] boss48;
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

			//int y = twice ? 2 : 1;
			//int y = most + 4;
			int y = 1;
			wide = 3 * 16;// (int)(y * size * scale);
			high = 64 + 6 * 16;// (int)(y * size * scale);

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
			//image01 = Content.Load<Texture2D>("sprites01");
			//image02 = Content.Load<Texture2D>("sprites02");

			//skulls = new Texture2D[2];
			//skulls[0] = Content.Load<Texture2D>("skull03");
			//skulls[1] = Content.Load<Texture2D>("skull04");

			int max = 16;
			data16 = new Texture2D[max + 2];
			for (int i = 4; i < max; i++)
			{
				int idx = i;
				var fle = idx.ToString().PadLeft(2, '0');
				var d16 = $"Index{fle}";
				data16[i - 4] = Content.Load<Texture2D>("16/" + d16);
			}
			for (int i = 0; i < 4; i++)
			{
				int idx = i;
				var fle = idx.ToString().PadLeft(2, '0');
				var d16 = $"Index{fle}";
				data16[i + 12] = Content.Load<Texture2D>("16/" + d16);
			}
			data16[16] = Content.Load<Texture2D>("16/Skull00");
			data16[17] = Content.Load<Texture2D>("16/Skull01");

			max = 6;
			boss24 = new Texture2D[max];
			boss48 = new Texture2D[max];
			for (int i = 0; i < max; i++)
			{
				int idx = i * 2 + 4;
				var fle = idx.ToString().PadLeft(2, '0');
				var n32 = $"Index{fle}";
				var n64 = $"Index{fle}";
				boss24[i] = Content.Load<Texture2D>("24/" + n32);
				boss48[i] = Content.Load<Texture2D>("48/" + n64);
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

				Draw();
				base.Draw(gameTime);

				GraphicsDevice.SetRenderTarget(null);
				Texture2D resolvedTexture = (Texture2D)renderTarget;

				//var xx = scale * size;
				//var yy = index.ToString().PadLeft(2, '0');
				//var yy = (index + 0).ToString().PadLeft(2, '0');
				//var file01 = $"spritemap.bmp";
				//var file02 = $"spritemap.png";
				var file02 = (index + 0).ToString().PadLeft(2, '0') + ".png";
				//Stream stream01 = File.Create("Images/" + file01);
				Stream stream02 = File.Create("Images/" + file02);

				resolvedTexture.SaveAsPng(stream02, wide, high);
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
			DrawVert();
			spriteBatch.End();
		}

		private void DrawVert()
		{
			spriteBatch.Draw(boss48[index], Vector2.Zero, Color.White);

			Vector2 pos;
			for (int j = 0; j < 3; j++)
			{
				for (int i = 0; i < 6; i++)
				{
					pos = new Vector2(j * 16, i * 16 + 64);
					spriteBatch.Draw(data16[j * 6 + i], pos, Color.White);
				}
			}
		}

		private void DrawAll()
		{
			Vector2 pos;
			// Boss 48
			for (int i = 0; i < 3; i++)
			{
				pos = new Vector2(i * 48, 0);
				spriteBatch.Draw(boss48[i], pos, Color.White);
			}
			for (int i = 0; i < 3; i++)
			{
				pos = new Vector2(i * 48, 64);
				spriteBatch.Draw(boss48[i + 3], pos, Color.White);
			}
			// Boss 24
			for (int i = 0; i < 6; i++)
			{
				pos = new Vector2(i * 24, 128);
				spriteBatch.Draw(boss24[i], pos, Color.White);
			}
			// Data 16
			for (int i = 0; i < 9; i++)
			{
				pos = new Vector2(i * 16, 160);
				spriteBatch.Draw(data16[i], pos, Color.White);
			}
			for (int i = 0; i < 9; i++)
			{
				pos = new Vector2(i * 16, 176);
				spriteBatch.Draw(data16[i + 9], pos, Color.White);
			}
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
			int[] arr = { 4, 5, 8, 9, 12, 13, 6, 7, 10, 11, 14, 15, 0, 1, 2, 3 };
			//int[] arr = { 4 };
			int x = 0;
			int y = 0;

			Vector2 pos;
			Texture2D draws = image01;
			for(int j = 0; j < arr.Length; j++)
			{
				draws = image01;
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
				pos = new Vector2(x, y);
				Rectangle dest = GetRectangle(i);
				spriteBatch.Draw(draws, pos, dest, Color.White);
			}

			// skulls n' crossbones
			//pos = new Vector2(0, 256 + 0);
			//spriteBatch.Draw(skulls[0], pos, Color.White);
			//pos = new Vector2(0, 256 + 16);
			//spriteBatch.Draw(skulls[1], pos, Color.White);
		}

		private void Draw3b()
		{
			int[] arr = { 0, 2, 4, 6, 3, 5 };
			int i = 0;
			for (int y = 0; y < 2; y++)
			{
				for (int x = 0; x < 3; x++)
				{
					int j = arr[i];
					int xx, yy;
					Texture2D image;
					Vector2 pos;
					xx = x * 64;
					yy = y * 64;
					image = boss48[j];
					pos = new Vector2(xx + 16, yy);
					spriteBatch.Draw(image, pos, Color.White);

					xx = x * 32;
					yy = y * 32;
					image = boss24[j];
					pos = new Vector2(xx + 16, yy + 128);
					spriteBatch.Draw(image, pos, Color.White);

					i++;
				}
			}
		}

		//private void Draw4()
		//{
		//	GraphicsDevice.Clear(Color.Black);
		//	spriteBatch.Begin();

		//	Rectangle dest = GetRectangle(index);
		//	//spriteBatch.Draw(image, new Vector2(0, 0), dest, Color.White, 0.0f, Vector2.Zero, scale, SpriteEffects.None, 1.0f);
		//	spriteBatch.Draw(skulls[0], new Vector2(0, 0), dest, Color.White);

		//	if (twice)
		//	{
		//		dest = GetRectangle(index + 1);
		//		//spriteBatch.Draw(image, new Vector2(0, size * scale), dest, Color.White, 0.0f, Vector2.Zero, scale, SpriteEffects.None, 1.0f);
		//		spriteBatch.Draw(image01, new Vector2(0, size * scale), dest, Color.White);
		//	}

		//	spriteBatch.End();
		//}

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