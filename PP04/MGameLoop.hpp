#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "object.hpp"

using namespace std;



namespace MuSeoun_Engine
{

	class MGameLoop
	{
	private :
		bool _isGameRunning;	
		MConsoleRenderer cRenderer;
		MConsoleRenderer cRenderer2;
		MConsoleRenderer cRenderer3;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;

		Player p;
		Object o;
		
	public :
		MGameLoop() 	{	_isGameRunning = false;		}
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			startRenderTimePoint = chrono::system_clock::now();
			while (_isGameRunning)
			{
				
				Input();
				Update();
				Render();
				

			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private :
		void Initialize()
		{
			
		}
		void Release() 
		{
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{ 
				p.isKeyPressed();
				o.isKeyPressedMove();
				
			}
			else 
			{
				p.isKeyUnpressed();
			}


		}
		void Update()
		{
			
		}
		void Render()
		{
			
			cRenderer.Clear();
			

			cRenderer.MoveCursor(p.x, p.y);
			cRenderer.DrawString("P");

			cRenderer2.MoveCursor(o.x, o.y);
			cRenderer2.DrawString("O");
			
			
			

			cRenderer.MoveCursor(10, 20);
			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();

			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(fps);

			string as = "¾ÈºÎµúÈû ";

			for (int i = 0; i < 10; i++) {
				--o.x;
			}

			cRenderer3.MoveCursor(20, 25);
			if (o.x <= 20) {
				as = "ºÎµúÈû ";
			}
			else {}		
			cRenderer3.DrawString(as);
			

			

			
			 
			this_thread::sleep_for(chrono::milliseconds(20));
		}


			////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

			//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
			//if (remainingFrameTime > 0)
			//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
		

				
		
	};

	


	

}