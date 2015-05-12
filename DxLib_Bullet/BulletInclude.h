#pragma once

#ifdef _DEBUG

#pragma comment(lib,"BulletCollision_Debug.lib")
#pragma comment(lib,"BulletDynamics_Debug.lib")
#pragma comment(lib,"BulletSoftBody_Debug.lib")
#pragma comment(lib,"LinearMath_Debug.lib")
#pragma comment(lib,"BulletFileLoader_Debug.lib")
#pragma comment(lib,"BulletMultiThreaded_Debug.lib")
#pragma comment(lib,"BulletSoftBodySolvers_OpenCL_Mini_Debug.lib")
#pragma comment(lib,"BulletWorldImporter_Debug.lib")
#pragma comment(lib,"BulletXmlWorldImporter_Debug.lib")
#pragma comment(lib,"ConvexDecomposition_Debug.lib")
#pragma comment(lib,"GIMPACTUtils_Debug.lib")
#pragma comment(lib,"GLUI_Debug.lib")
#pragma comment(lib,"HACD_Debug.lib")
#pragma comment(lib,"MiniCL_Debug.lib")
#pragma comment(lib,"OpenGLSupport_Debug.lib")


#else

#pragma comment(lib,"BulletCollision.lib")
#pragma comment(lib,"BulletDynamics.lib")
#pragma comment(lib,"BulletSoftBody.lib")
#pragma comment(lib,"LinearMath.lib")
#pragma comment(lib,"BulletFileLoader.lib")
#pragma comment(lib,"BulletMultiThreaded.lib")
#pragma comment(lib,"BulletSoftBodySolvers_OpenCL_Mini.lib")
#pragma comment(lib,"BulletWorldImporter.lib")
#pragma comment(lib,"BulletXmlWorldImporter.lib")
#pragma comment(lib,"ConvexDecomposition.lib")
#pragma comment(lib,"GIMPACTUtils.lib")
#pragma comment(lib,"GLUI.lib")
#pragma comment(lib,"HACD.lib")
#pragma comment(lib,"MiniCL.lib")
#pragma comment(lib,"OpenGLSupport.lib")

#endif