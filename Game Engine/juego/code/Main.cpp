/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief Game Main fuction

//no inclur aqui sdl.h ni directa ni indirectamente

// si se tiene que incluir poner #undef main

#include <Scene.hpp>
#include <PlayerController.hpp>
#include <assert.h>
int main()
{
	misi::Scene * MainScene=new misi::Scene("The DreamCruse 2", 1280, 720,false);
	
	MainScene->run();
	//aqui no llega hasta acabar el bucle

	
	return 0;
}

	unsigned checkNumberposition(vector<float> position)
	{
		//1 -22,0,-8  -22,0,-16  -16,0,-16
		// 
		//2 16,0,-8  22,0,-8  22,0,-14
		// 
		//3 16,0,6  16,0,12  22,0,12
		//
		//4 -22,0,6 -22,0,12  -16,0,12
		//
		//5 2,0,-2  2,0,8   -6,0,8
		if (position[0]>=-22 && position[0] <= -14 && position[2]>= -14 && position[2] <= -8)
		{
			return 1;
		}
		if (position[0] <= 22 && position[0] >= 16 && position[2] >= -14 && position[2] <= -8)
		{
			return 2;
		}
		if (position[0] <= 22 && position[0] >= 16 && position[2] <= 12 && position[2] >= 6)
		{
			return 3;
		}
		if (position[0] >= -22 && position[0] <= -14 && position[2] <= 12 && position[2] >= 6)
		{
			return 4;
		}
		if (position[0] <= 0 && position[0] >= -6 && position[2] >= -10 && position[2] <= -2)
		{
			return 5;
		}
		return 0;

	}
namespace misi
{

	/// @brief players define what the inputs do in here, they can also call messages to the engine
	void player_controller::handle(const Message& message)
	{
		std::string key;
		parameter value;
		std::string key_d;
		std::pair<parameter, parameter> value_d;
		Message_Dispacher* message_dispacher;
		std::map<std::string, parameter> parameters;
		std::map<std::string, std::pair<parameter, parameter>> double_parameters;
		vector<float> position;
		message_dispacher = this->get_dispacher();
		Message player_mensage("RenderManager", parameters);


		static vector<float> player_position;
		player_position.push_back(0);
		player_position.push_back(0);
		player_position.push_back(0);
		static bool game_ended = false;
		static unsigned int currentnumber=0;

		for (const auto& entry : message.parameters) {
			key = entry.first;
			value = entry.second;
		}
		for (const auto& entry : message.double_parameters) {
			key_d = entry.first;
			value_d = entry.second;
		}
		if (key == "A")
		{
			if (player_position[0] > -28)
			{
				double_parameters.clear();
				parameters.clear();
				vector<float> position;
				position.push_back(-2);
				position.push_back(0);
				position.push_back(0);
				double_parameters.insert(std::make_pair("Move Model", std::make_pair("player", position)));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				parameters.insert(std::make_pair("Get Position", "player"));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);

			}
			else if (game_ended)
			{

				double_parameters.clear();
				parameters.clear();
				vector<float> position;
				position.push_back(-2);
				position.push_back(0);
				position.push_back(0);
				double_parameters.insert(std::make_pair("Move Model", std::make_pair("player", position)));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);
			}
			else
			{
				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Change Sound Clip", "../../asset/rock_break.wav"));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Play Sound", " "));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);
			}
		}
		if (key == "D")
		{
			if (player_position[0] < 28)
			{
				parameters.clear();
				vector<float> position;
				position.push_back(2);
				position.push_back(0);
				position.push_back(0);
				double_parameters.insert(std::make_pair("Move Model", std::make_pair("player", position)));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				parameters.insert(std::make_pair("Get Position", "player"));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);
			}
			else if (game_ended)
			{
				parameters.clear();
				vector<float> position;
				position.push_back(2);
				position.push_back(0);
				position.push_back(0);
				double_parameters.insert(std::make_pair("Move Model", std::make_pair("player", position)));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);
			}
			else
			{
				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Change Sound Clip", "../../asset/rock_break.wav"));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Play Sound", " "));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);
			}
			
		}
		if (key == "W")
		{
			if (player_position[2] > -24)
			{
				parameters.clear();
				vector<float> position;
				position.push_back(0);
				position.push_back(0);
				position.push_back(-2);
				double_parameters.insert(std::make_pair("Move Model", std::make_pair("player", position)));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				parameters.insert(std::make_pair("Get Position", "player"));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);

			}
			else if (game_ended)
			{
				parameters.clear();
				vector<float> position;
				position.push_back(0);
				position.push_back(0);
				position.push_back(-2);
				double_parameters.insert(std::make_pair("Move Model", std::make_pair("player", position)));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);
			}
			else
			{
				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Change Sound Clip", "../../asset/rock_break.wav"));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Play Sound", " "));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);
			}
		}
		if (key == "S")
		{
			if (player_position[2] < 14)
			{
				parameters.clear();
				vector<float> position;
				position.push_back(0);
				position.push_back(0);
				position.push_back(2);
				double_parameters.insert(std::make_pair("Move Model", std::make_pair("player", position)));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				parameters.insert(std::make_pair("Get Position", "player"));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);

			}
			else if (game_ended)
			{
				parameters.clear();
				vector<float> position;
				position.push_back(0);
				position.push_back(0);
				position.push_back(2);
				double_parameters.insert(std::make_pair("Move Model", std::make_pair("player", position)));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);
			}
			else
			{
				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Change Sound Clip", "../../asset/rock_break.wav"));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Play Sound", " "));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);
			}
		}
		if (key == "Start")
		{
			
			parameters.insert(std::make_pair("Add Cube", "player"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

		#pragma region number1
			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "1cube1"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "1cube2"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "1cube3"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "1cube4"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "1cube5"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "1cubeM"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-2);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("1cube2", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("1cube3", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-6);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("1cube4", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-2);
			position.push_back(0);
			position.push_back(-6);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("1cube5", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("1cube1", "1cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("1cube2", "1cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("1cube3", "1cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("1cube4", "1cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("1cube5", "1cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-20);
			position.push_back(0);
			position.push_back(-10);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("1cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);
		#pragma endregion
		#pragma region number2
			double_parameters.clear();
			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "2cube1"));
			player_mensage.set_params(parameters);
			player_mensage.set_params(double_parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "2cube2"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "2cube3"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "2cube4"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "2cube5"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "2cube6"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "2cube7"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "2cube8"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "2cube9"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "2cubeM"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(4);
			position.push_back(0);
			position.push_back(0);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("2cube2", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(2);
			position.push_back(0);
			position.push_back(0);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("2cube3", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-2);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("2cube4", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(2);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("2cube5", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			
			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(4);
			position.push_back(0);
			position.push_back(-6);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("2cube6", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(4);
			position.push_back(0);
			position.push_back(-8);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("2cube7", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(2);
			position.push_back(0);
			position.push_back(-8);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("2cube8", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-8);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("2cube9", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("2cube1", "2cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("2cube2", "2cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("2cube3", "2cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("2cube4", "2cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("2cube5", "2cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("2cube6", "2cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("2cube7", "2cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("2cube8", "2cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("2cube9", "2cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(20);
			position.push_back(0);
			position.push_back(-10);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("2cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);
#pragma endregion
		#pragma region number3
			double_parameters.clear();
			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "3cube1"));
			player_mensage.set_params(parameters);
			player_mensage.set_params(double_parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "3cube2"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "3cube3"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "3cube4"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "3cube5"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "3cube6"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "3cube7"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "3cube8"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "3cubeM"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-2);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("3cube2", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("3cube3", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-6);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("3cube4", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-8);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("3cube5", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-2);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("3cube6", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-2);
			position.push_back(0);
			position.push_back(-8);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("3cube7", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-2);
			position.push_back(0);
			position.push_back(0);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("3cube8", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);



			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("3cube1", "3cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("3cube2", "3cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("3cube3", "3cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("3cube4", "3cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("3cube5", "3cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("3cube6", "3cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("3cube7", "3cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("3cube8", "3cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(20);
			position.push_back(0);
			position.push_back(10);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("3cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);
			#pragma endregion
		#pragma region number4
			double_parameters.clear();
			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "4cube1"));
			player_mensage.set_params(parameters);
			player_mensage.set_params(double_parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "4cube2"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "4cube3"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "4cube4"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "4cube5"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "4cube6"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "4cube7"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "4cube8"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "4cube9"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "4cubeM"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-2);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("4cube2", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("4cube3", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-6);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("4cube4", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-8);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("4cube5", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-2);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("4cube6", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-4);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("4cube7", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-4);
			position.push_back(0);
			position.push_back(-6);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("4cube8", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-4);
			position.push_back(0);
			position.push_back(-8);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("4cube9", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("4cube1", "4cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("4cube2", "4cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("4cube3", "4cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("4cube4", "4cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("4cube5", "4cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("4cube6", "4cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("4cube7", "4cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("4cube8", "4cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("4cube9", "4cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);



			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-20);
			position.push_back(0);
			position.push_back(10);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("4cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

#pragma endregion
		#pragma region number5
			double_parameters.clear();
			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "5cube1"));
			player_mensage.set_params(parameters);
			player_mensage.set_params(double_parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "5cube2"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "5cube3"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "5cube4"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "5cube5"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "5cube6"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "5cube7"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "5cube8"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "5cube9"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);
			parameters.clear();

			parameters.insert(std::make_pair("Add Cube", "5cube10"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);
			parameters.clear();

			parameters.insert(std::make_pair("Add Cube", "5cube11"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "5cubeM"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(2);
			position.push_back(0);
			position.push_back(0);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cube2", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(4);
			position.push_back(0);
			position.push_back(0);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cube3", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(4);
			position.push_back(0);
			position.push_back(-2);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cube4", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(4);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cube5", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(2);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cube6", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cube7", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-6);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cube8", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-8);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cube9", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(2);
			position.push_back(0);
			position.push_back(-8);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cube10", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(4);
			position.push_back(0);
			position.push_back(-8);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cube11", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube1", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube2", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube3", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube4", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube5", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube6", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube7", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube8", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube9", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube10", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Add Parent", std::make_pair("5cube11", "5cubeM")));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-2);
			position.push_back(0);
			position.push_back(-4);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("5cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);
		#pragma endregion
		#pragma region addWalls
		

			double_parameters.clear();
			position.clear();
			player_mensage.set_params(double_parameters);
			for (int i = 1; i <= 5; ++i) {
			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "Wcube" + std::to_string(i)));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);
			}

			position.clear();
			parameters.clear();
			parameters.insert(std::make_pair("Add Cube", "WcubeM"));
			player_mensage.set_params(parameters);
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(30);
			position.push_back(0);
			position.push_back(0);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("Wcube1", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(1);
			position.push_back(1);
			position.push_back(25);
			double_parameters.insert(std::make_pair("Scale", std::make_pair("Wcube1", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(-30);
			position.push_back(0);
			position.push_back(0);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("Wcube2", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(1);
			position.push_back(1);
			position.push_back(25);
			double_parameters.insert(std::make_pair("Scale", std::make_pair("Wcube2", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(-26);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("Wcube3", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(30);
			position.push_back(1);
			position.push_back(1);
			double_parameters.insert(std::make_pair("Scale", std::make_pair("Wcube3", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);


			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0);
			position.push_back(16);
			double_parameters.insert(std::make_pair("Move Model", std::make_pair("Wcube4", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(30);
			position.push_back(1);
			position.push_back(1);
			double_parameters.insert(std::make_pair("Scale", std::make_pair("Wcube4", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			for (int i = 1; i <= 5; ++i) {
				double_parameters.clear();
				parameters.clear();
				position.clear();
				double_parameters.insert(std::make_pair("Add Parent", std::make_pair("Wcube" + std::to_string(i), "WcubeM")));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);
			}

			double_parameters.clear();
			parameters.clear();
			position.clear();
			double_parameters.insert(std::make_pair("Set visible", std::make_pair("WcubeM", "False")));//buged
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);
			
		#pragma endregion
		#pragma region finishTouch
			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0.5f);
			position.push_back(0.5f);
			position.push_back(0.5f);
			double_parameters.insert(std::make_pair("Scale", std::make_pair("1cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0.5f);
			position.push_back(0.5f);
			position.push_back(0.5f);
			double_parameters.insert(std::make_pair("Scale", std::make_pair("2cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0.5f);
			position.push_back(0.5f);
			position.push_back(0.5f);
			double_parameters.insert(std::make_pair("Scale", std::make_pair("3cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0.5f);
			position.push_back(0.5f);
			position.push_back(0.5f);
			double_parameters.insert(std::make_pair("Scale", std::make_pair("4cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0.5f);
			position.push_back(0.5f);
			position.push_back(0.5f);
			double_parameters.insert(std::make_pair("Scale", std::make_pair("5cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

		#pragma endregion

		}

		if (key == "Return Position")
		{
			player_position.clear();
			player_position = std::get<std::vector<float>>(value);
			unsigned near_number = checkNumberposition(player_position);
			if (near_number == currentnumber+1)
			{
				currentnumber++;
				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Change Sound Clip", "../../asset/correct_sound_effect.wav"));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Play Sound", " "));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				vector<float> position;
				player_mensage.set_id("RenderManager");
				position.push_back(200);
				position.push_back(0);
				position.push_back(200);
				double_parameters.insert(std::make_pair("Move Model", std::make_pair(std::to_string(currentnumber)+"cubeM", position)));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);
				
			}
			else if (near_number > currentnumber)
			{
				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Change Sound Clip", "../../asset/wrong_sound_effect.wav"));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);

				double_parameters.clear();
				parameters.clear();
				player_mensage.set_id("AudioManager");
				parameters.insert(std::make_pair("Play Sound", " "));
				player_mensage.set_params(parameters);
				player_mensage.set_params(double_parameters);
				message_dispacher->send(player_mensage);
			}
			if (currentnumber == 5)
			{
				currentnumber++;
				double_parameters.clear();
				parameters.clear();
				vector<float> position;
				player_mensage.set_id("RenderManager");
				position.push_back(100);
				position.push_back(0);
				position.push_back(100);
				double_parameters.insert(std::make_pair("Move Model", std::make_pair("WcubeM", position)));
				player_mensage.set_params(double_parameters);
				player_mensage.set_params(parameters); //necesarty to set it null
				message_dispacher->send(player_mensage);
				game_ended = true;
			}
			//3 16,0,-8  22,0,-8  22,0,-14
		}

		if (key == "Update")
		{

			player_mensage.set_id("RenderManager");
			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0.0002f);
			position.push_back(0.0003f);
			double_parameters.insert(std::make_pair("Rotate", std::make_pair("1cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0.0002f);
			position.push_back(0.0003f);
			double_parameters.insert(std::make_pair("Rotate", std::make_pair("2cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0.0002f);
			position.push_back(0.0003f);
			double_parameters.insert(std::make_pair("Rotate", std::make_pair("3cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0.0002f);
			position.push_back(0.0003f);
			double_parameters.insert(std::make_pair("Rotate", std::make_pair("4cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);

			double_parameters.clear();
			parameters.clear();
			position.clear();
			position.push_back(0);
			position.push_back(0.0002f);
			position.push_back(0.0003f);
			double_parameters.insert(std::make_pair("Rotate", std::make_pair("5cubeM", position)));
			player_mensage.set_params(double_parameters);
			player_mensage.set_params(parameters); //necesarty to set it null
			message_dispacher->send(player_mensage);
		}
	}

}


