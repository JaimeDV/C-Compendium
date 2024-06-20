/// @copyright � 2023+ Jaime d�az vi�itez
/// @author Author: Jaime D�az Vi�itez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief defines the plane class and the relevant methods

#pragma once

namespace misi
{
	//https://gdbooks.gitbooks.io/3dcollisions/content/Chapter1/three_plane_intersection.html consultar

	template<typename TYPE>
	class Plane
	{
		TYPE northWestPoint;
		TYPE northEastPoint;
		TYPE southEastPoint;
		TYPE southWestPoint;
		TYPE centerPoint;

	public:
		Plane(TYPE& nW, TYPE& nE, TYPE& sE, TYPE& sW, TYPE& cP)
		{
			northWestPoint = nW;
			northEastPoint = nE;
			southEastPoint = sE;
			southWestPoint = sW;
			centerPoint = cP;
		}
	};
}