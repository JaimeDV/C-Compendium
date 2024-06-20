/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 26/12/2023
/// @brief implements the classes defined in kernel

#include "../headers/Kernel.hpp"
#include "../headers/Task.hpp"

namespace misi
{
	/// @brief dstatrs the engine loop calling the apropiate tasks, does not implement wait time at the moment
	void Kernel::run()
	{
		exit = false;
		float frame_duration = 1.f / 60.f;
		
		

		do {
			for (const auto& task : tasks)
			{
				set_exit(task->execute(frame_duration));
				if (task->get_consumable() == true)
				{
					tasks.remove(task);
				}
				if (exit)
				{
					break;
				}
				std::map<std::string, parameter> parameters;
				Message scene_message("PlayerManager", parameters);
				scene_message.set_id("PlayerManager");
				parameters.insert(std::make_pair("Update", 0));
				scene_message.set_params(parameters);
				dispacher->send(scene_message);
			}
			//frameduration = ? ? ? ? //cortormetaje, una buena estimación es cuanto tardo el anterior
		} while (not exit);

		

	}
}


