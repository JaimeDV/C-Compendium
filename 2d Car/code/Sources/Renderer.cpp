/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 24/02/2024
/// @brief impelementation class for the behaviours defined in renderer.hpp


#include "../Headers/Render.hpp"
namespace misi
{
    Renderer::Renderer(physicWorld& givenWorld, RenderWindow& givenWindow, float givenScale) :
    world(*givenWorld.getWorldReference()), window(givenWindow), scale(givenScale)
    {
       window_height = (float)window.getSize().y;
    }
    void Renderer::Render()
    {
        for (b2Body* body = world.GetBodyList(); body != nullptr; body = body->GetNext())
        {
          
            const b2Transform& body_transform = body->GetTransform();


            for (b2Fixture* fixture = body->GetFixtureList(); fixture != nullptr; fixture = fixture->GetNext())
            {

                b2Shape::Type shape_type = fixture->GetShape()->GetType();

                if (shape_type == b2Shape::e_circle)
                {
              
                    b2CircleShape* circle = dynamic_cast<b2CircleShape*>(fixture->GetShape());

                    float  radius = circle->m_radius * scale;
                    b2Vec2 center = circle->m_p;

                    CircleShape shape;

                    shape.setPosition(box2dPositionToSfmlPosition(b2Mul(body_transform, center), window_height, scale) - Vector2f(radius, radius));
                    if (fixture->IsSensor() == true || fixture->GetBody()->IsEnabled() == false)
                    {
                        shape.setFillColor(Color::Transparent);
                    }
                    else
                    {
                        shape.setFillColor(Color::Blue);
                    }
                    shape.setRadius(radius);

                    window.draw(shape);
                }
                else
                    if (shape_type == b2Shape::e_edge)
                    {
                        
                        b2EdgeShape* edge = dynamic_cast<b2EdgeShape*>(fixture->GetShape());

                        b2Vec2 start = b2Mul(body_transform, edge->m_vertex1);
                        b2Vec2 end = b2Mul(body_transform, edge->m_vertex2);

                        Vertex line[] =
                        {
                            Vertex(box2dPositionToSfmlPosition(start, window_height, scale), Color::Green),
                            Vertex(box2dPositionToSfmlPosition(end, window_height, scale), Color::Green),
                        };

                        window.draw(line, 2, Lines);
                    }
                    else
                        if (shape_type == b2Shape::e_polygon)
                        {
                            b2PolygonShape* box2d_polygon = dynamic_cast<b2PolygonShape*>(fixture->GetShape());
                            ConvexShape       sfml_polygon;

                            int number_of_vertices = box2d_polygon->m_count;

                            sfml_polygon.setPointCount(number_of_vertices);
                            if (fixture->IsSensor() == true || fixture->GetBody()->IsEnabled() == false)
                            {
                                sfml_polygon.setFillColor(Color::Transparent);
                            }
                            else
                            {
                                sfml_polygon.setFillColor(Color::Magenta);
                            }
                            for (int index = 0; index < number_of_vertices; index++)
                            {
                                sfml_polygon.setPoint
                                (
                                    index,
                                    box2dPositionToSfmlPosition(b2Mul(body_transform, box2d_polygon->m_vertices[index]), window_height, scale)
                                );
                            }

                            window.draw(sfml_polygon);
                        }
            }
        }
    }
}