
#include "../Headers/node.hpp"
namespace misi
{
    void Node::SetAngle(float given_angle)
    {
        angle = given_angle;
        SetMatrix();
    }

    void Node::SetScale(float given_scale)
    {
        scaleFactor = given_scale;
        SetMatrix();
    }

    void Node::SetPosition(math::Vector3f given_position)
    {
        position = given_position;
        SetMatrix();
    }
    /*void Node::SetFatherTransform()
    {
        std::vector<Matrix44>transforms;
        if (father != nullptr)
        {
            Node* dad = father;
            while (dad)
            {
                dad = father->GetFather();
                if (dad)
                {
                    transforms.push_back(dad->GetTransform());
                }
            }

        }
        for (auto & fatherTransform : transforms)
        {
            transformation *= fatherTransform;
        }
        
    }*/
}