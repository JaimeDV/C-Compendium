/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 27/12/2023
/// @brief Defines entity funtions, cuarently unused


#pragma once
//ECS
//las entidades
//los componentes son clases que solo guardan datos,
//para checkear los valores de datos se encargan los sistemas
//
//los gameobjects heredan piezas con propiedades, estas
//tienen codigo, es decir gana por composición no herencia
//
//sonido podria ser un componente, collider,
namespace misi
{

	class Entity //actor, gameobject only data
	{
		map < String, shared_ptr<Component> components //string identificador

			Transform_Component transform; //esta qui popr qse usa mucho

	public: //puede tener codigo si es un get ser

		component* get component_by_id(const std::string& id) //los ids tienen que estar documentados
		{
			auto item = component.find(id);
			if (item != components.end()) {
				return item->second.get();
			}
		}

		Transform_Component& getTransfor() {
			return transform;
		}
		const Transform_Component& getTransfor()const {
			return transform;
		}
	};

	struct Component //para cojer otros componentes los pillas del owner
	{
		Entity* owner;
		virtual ~component() = default;
	}

	struct Transform_Component : public Component //<- componente importante
	{
		Transform component* parent
			gml::vec3 Position;
		gml::vec3 Scale;
		gml::vec3 rotation;

		gml::Mp4 get_transform_matrix()
		{
			gml::mat4 matrix(1);
			matrix = gml::translate(matrix, position);
			matrix = gml::scale(matrix, scale);
			matrix = gml::rotate(matrix, rotation.x, gml::vec3(1, 0, 0));
			return matrix;
		}
	};

	struct ModelComponent : public Component
	{
		shared_ptr<glt::Model> model; //una malla son grupo de vertices, un modelo un conjunto de mallas
		//Model esta en opengl Toolkit
	};

	struct Camera_Component : public Component
	{
		shared_ptr<glt::Camera> camera
	};

	struct Light_Component : public Component
	{
		shared_ptr<glt::Light> camera
	};

	struct Audio
	{
		shared_ptr<Audio> audio; //audio task
	};

	auto model = make_shared<glt::Model_obj>("..url")

	Cada scene tiene las entidades

	Sistemas

	//probablemente no haga esto

	//rapidXML

	class System : public Task //factorias de componentes
	{
	public:

		virtual shared_ptr<component> create component
		(const std::string& component_id, const xml_node* data) = 0;
	};

	class Render_system : public System
	{
		shared_ptr<componet> create component
		{
			const std::strinf & component_id,
			const xml_node * data
		}
			override{
		}
		void execute(float t) override
		{
			for (auto& component::components)
			{
				gml::mat4 transform_matrix = componet->owner->getTransformmatrix

					auto model = dinamyc_cast<model_component> (component.get());
			}

			renderer.render();

			scene->get_window()->swap buffer();
			//para cada componenyt
			//aplicarle el transform de la entidad
			//llamar al metodo render de renderer
			//invocar swap buffers
		}

		Si no se usa no cuenta para la practica
	};
}