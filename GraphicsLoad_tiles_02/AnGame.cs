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
		//Texture2D font;
		Texture2D[] bonus;
		Texture2D[] candy;
		Texture2D[] miscs;
		Texture2D[] trees;
		Texture2D[] titles;
		Texture2D title;

		RenderTarget2D renderTarget;

		const int size = 16;
		const int most = 12;
		//int index = 0;
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
			wide = 208;// (int)(size * scale);
			high = 48;// (int)(y * size * scale);

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

			const string bonusDirX = "Bonus05";
			const string candyDirX = "Candy05";

			//font = Content.Load<Texture2D>("font_line");
			var names = new string[] { "BlueSpiral", "CoolTriangle", "LoveHeart", "PawPrint" };
			const int bns = 4;
			bonus = new Texture2D[bns * 2];
			for (int idx = 0; idx < bns; idx++)
			{
				var name = names[idx];
				var flip = name + "_Flip";
				bonus[idx] = Content.Load<Texture2D>(bonusDirX + "/" + name);
				bonus[idx + 4] = Content.Load<Texture2D>(bonusDirX + "/" + flip);
			}

            const int max = 14;
			candy = new Texture2D[max];
			for (int idx = 0; idx < max; idx++)
			{
				var file = (idx + 2).ToString().PadLeft(2, '0');
				//var text = $"Candy/Candy{file}";
				var text = $"{candyDirX}/Candy{file}";
				candy[idx] = Content.Load<Texture2D>(text);
			}

			var root = $"{candyDirX}/Candy";
			miscs = new Texture2D[3];
			miscs[0] = Content.Load<Texture2D>(root + "00");
			miscs[1] = Content.Load<Texture2D>(root + "15");
			miscs[2] = Content.Load<Texture2D>(root + "16");

			trees = new Texture2D[2];
			trees[0] = Content.Load<Texture2D>("Trees/tree_avoid");
			trees[1] = Content.Load<Texture2D>("Trees/tree_death");

			title = Content.Load<Texture2D>("game_title");
			titles = new Texture2D[2];
			titles[0] = Content.Load<Texture2D>("title_Candy");
			titles[1] = Content.Load<Texture2D>("title_Kid");

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

				var file = $"main_tiles.png";
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
			//Draw_02lines();
			Draw_03lines();
		}

		private void Draw_02lines()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			//spriteBatch.Draw(font, new Vector2(8, 0), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 8), new Rectangle(200, 0, 512, 8), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 16), new Rectangle(408, 0, 48, 8), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 24), new Rectangle(456, 0, 48, 8), Color.White);

			spriteBatch.Draw(trees[0], new Vector2(0, 0), Color.White);
			spriteBatch.Draw(trees[1], new Vector2(16, 0), Color.White);

			// bonus
			Texture2D image;
			Vector2 pos;
			for(int idx = 0; idx < bonus.Length; idx++)
			{
				image = bonus[idx];
				//var image = bonus02[idx];
				pos = new Vector2(32 + idx * size, 0);
				spriteBatch.Draw(image, pos, Color.White);
			}

			// bonusflip
			//for(int idx = 0; idx < bonus.Length; idx++)
			//{
			//	//var image = bonus[idx];
			//	var image = bonus[idx + 4];
			//	var pos = new Vector2(96 + idx * size, 0);
			//	spriteBatch.Draw(image, pos, Color.White);
			//}

			// miscellaneous candy
			for(int idx = 0; idx < 3; idx++)
			{
				image = miscs[idx];
				pos = new Vector2(160 + idx * size, 0);
				spriteBatch.Draw(image, pos, Color.White);
			}



			// normal candy
			for(int idx = 1; idx < 13; idx++)
			{
				image = candy[idx];
				pos = new Vector2((idx - 1) * size, 16);
				spriteBatch.Draw(image, pos, Color.White);
			}

			// Last candy repeat
			pos = new Vector2(192, 16);
			spriteBatch.Draw(candy[2], pos, Color.White);

			//spriteBatch.Draw(candy[13], new Vector2(208 - 16, 16), Color.White);

			spriteBatch.Draw(title, new Vector2(0, 32), Color.White);

			spriteBatch.End();
		}

		private void Draw_03lines()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			//spriteBatch.Draw(font, new Vector2(8, 0), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 8), new Rectangle(200, 0, 512, 8), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 16), new Rectangle(408, 0, 48, 8), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 24), new Rectangle(456, 0, 48, 8), Color.White);

			spriteBatch.Draw(trees[0], new Vector2(0, 0), Color.White);
			spriteBatch.Draw(trees[1], new Vector2(16, 0), Color.White);

			// bonus
			for (int idx = 0; idx < bonus.Length; idx++)
			{
				var image = bonus[idx];
				//var image = bonus02[idx];
				var pos = new Vector2(32 + idx * size, 0);
				spriteBatch.Draw(image, pos, Color.White);
			}

			// bonusflip
			//for (int idx = 0; idx < bonus.Length; idx++)
			//{
			//	//var image = bonus[idx];
			//	var image = bonus[idx + 4];
			//	var pos = new Vector2(96 + idx * size, 0);
			//	//spriteBatch.Draw(image, pos, Color.White);
			//}

			//candy
			for (int idx = 0; idx < 6; idx++)
			{
				var image = candy[idx];
				var pos = new Vector2(96 + idx * size, 0);
				spriteBatch.Draw(image, pos, Color.White);
			}

			//for (int idx = 2; idx < 13; idx++)
			//{
			//	var image = candy[idx];
			//	var pos = new Vector2((idx - 2) * size, 16);
			//	spriteBatch.Draw(image, pos, Color.White);
			//}

			spriteBatch.Draw(miscs[0], new Vector2(208 - 16, 0), Color.White);

			//int[] arr = { 2, 3, 4, 5, 6, 7, 8, 10, 11, 13, 9, 12, 14, 15 };
			//for (int idx = 0; idx < 14; idx++)
			//{
			//	int bob = arr[idx];
			//	bob -= 2;
			//	var image = candy[bob];
			//	var pos = new Vector2(0, 128 + 64 + idx * size);
			//	spriteBatch.Draw(image, pos, Color.White);
			//}

			spriteBatch.Draw(title, new Vector2(0, 16), Color.White);

			spriteBatch.End();
		}

		private void DrawAll()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			//spriteBatch.Draw(font, new Vector2(8, 0), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 8), new Rectangle(200, 0, 512, 8), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 16), new Rectangle(408, 0, 48, 8), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 24), new Rectangle(456, 0, 48, 8), Color.White);

			spriteBatch.Draw(trees[0], new Vector2(0, 0), Color.White);
			spriteBatch.Draw(trees[1], new Vector2(16, 0), Color.White);

			// bonus
			for (int idx = 0; idx < bonus.Length; idx++)
			{
				var image = bonus[idx];
				//var image = bonus02[idx];
				var pos = new Vector2(32 + idx * size, 0);
				spriteBatch.Draw(image, pos, Color.White);
			}

			// bonusflip
			//for (int idx = 0; idx < bonus.Length; idx++)
			//{
			//	//var image = bonus[idx];
			//	var image = bonus[idx + 4];
			//	var pos = new Vector2(96 + idx * size, 0);
			//	spriteBatch.Draw(image, pos, Color.White);
			//}

			//candy
			for (int idx = 0; idx < 2; idx++)
			{
				var image = candy[idx];
				var pos = new Vector2(160 + idx * size, 0);
				spriteBatch.Draw(image, pos, Color.White);
			}

			for (int idx = 2; idx < 13; idx++)
			{
				var image = candy[idx];
				var pos = new Vector2((idx - 2)* size, 16);
				spriteBatch.Draw(image, pos, Color.White);
			}

			spriteBatch.Draw(candy[13], new Vector2(192 - 16, 16), Color.White);

			//int[] arr = { 2, 3, 4, 5, 6, 7, 8, 10, 11, 13, 9, 12, 14, 15 };
			//for (int idx = 0; idx < 14; idx++)
			//{
			//	int bob = arr[idx];
			//	bob -= 2;
			//	var image = candy[bob];
			//	var pos = new Vector2(0, 128 + 64 + idx * size);
			//	spriteBatch.Draw(image, pos, Color.White);
			//}

			spriteBatch.Draw(titles[0], new Vector2(0, 32), Color.White);
			spriteBatch.Draw(titles[1], new Vector2(200-64, 32), Color.White);

			spriteBatch.End();
		}

		private void Draw_bak()
		{
			GraphicsDevice.Clear(Color.Black);
			spriteBatch.Begin();

			//spriteBatch.Draw(font, new Vector2(8, 0), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 8), new Rectangle(200, 0, 512, 8), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 16), new Rectangle(408, 0, 48, 8), Color.White);
			//spriteBatch.Draw(font, new Vector2(0, 24), new Rectangle(456, 0, 48, 8), Color.White);

			spriteBatch.Draw(trees[0], new Vector2(48, 16), Color.White);
			spriteBatch.Draw(trees[1], new Vector2(64, 16), Color.White);

			// bonus
			for (int idx = 0; idx < bonus.Length; idx++)
			{
				var image = bonus[idx];
				//var image = bonus02[idx];
				var pos = new Vector2(80 + idx * size, 16);
				spriteBatch.Draw(image, pos, Color.White);
			}

			// bonusflip
			//for (int idx = 0; idx < bonus.Length; idx++)
			//{
			//	//var image = bonus[idx];
			//	var image = bonus[idx + 4];
			//	var pos = new Vector2(144 + idx * size, 16);
			//	spriteBatch.Draw(image, pos, Color.White);
			//}

			//candy
			//int[] arr = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
			for (int idx = 0; idx < 12; idx++)
			{
				var image = candy[idx];
				var pos = new Vector2(0 + idx * size, 32);
				spriteBatch.Draw(image, pos, Color.White);
			}

			spriteBatch.Draw(candy[13], new Vector2(208 - 16, 32), Color.White);

			//int[] arr = { 2, 3, 4, 5, 6, 7, 8, 10, 11, 13, 9, 12, 14, 15 };
			//for (int idx = 0; idx < 14; idx++)
			//{
			//	int bob = arr[idx];
			//	bob -= 2;
			//	var image = candy[bob];
			//	var pos = new Vector2(0, 128 + 64 + idx * size);
			//	spriteBatch.Draw(image, pos, Color.White);
			//}

			//spriteBatch.Draw(title, new Vector2(0, 48), Color.White);
			spriteBatch.End();
		}

	}
}