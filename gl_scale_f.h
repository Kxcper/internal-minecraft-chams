#pragma once  
#define WIN32_LEAN_AND_MEAN
#include <windows.h> 
#include <GL/gl.h>  
#include "minhook/MinHook.h"

#pragma comment(lib, "opengl32.lib")

namespace hooks {

	typedef auto (APIENTRY* glScalef_t)(GLfloat, GLfloat, GLfloat) -> void;
	inline glScalef_t ogl_scale_f = nullptr;

	inline auto gl_scale_f_hk(GLfloat x, GLfloat y, GLfloat z) -> void {

		bool player_layer = (x == 0.9375f && y == 0.9375f && z == 0.9375f);

		if (player_layer) {
			glPolygonOffset(1.0f, -1100000.0f);

			glEnable(GL_POLYGON_OFFSET_FILL);

			/* disables texture drawing (players will instead be a flat colour) */
			//glDisable(GL_TEXTURE_2D);

			/* colours the model in, modifying the color changes the hue of the skin, by default 1,1,1,1 = no hue */
			glColor4f(1, 1, 1, 1);

			/* self explanatory - disables lighting making entities brighter */
			glDisable(GL_LIGHTING);
		}
		ogl_scale_f(x, y, z);
	}

	inline auto init() -> void {
		MH_Initialize();
		MH_CreateHookApi(L"opengl32.dll", "glScalef", gl_scale_f_hk, (void**)&ogl_scale_f);
		MH_EnableHook(MH_ALL_HOOKS);
	}

	inline auto dispose() -> void {
		MH_DisableHook(MH_ALL_HOOKS);
		MH_Uninitialize();
	}
}