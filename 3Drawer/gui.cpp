#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "gui.h"
#include <GL/glew.h>
#include <string.h>

void menuBar::menubarRender() {
	ImGui::SetNextWindowPos(ImVec2((float)xBar, (float)yBar));
	ImGui::SetNextWindowSize(ImVec2((float)widthBar, (float)heightBar));
	ImGui::Begin("window Baru", &my_tool_activate, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove
		| ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_MenuBar);
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
			if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
			if (ImGui::MenuItem("Close", "Ctrl+W")) { my_tool_activate = false; }
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
			if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
			if (ImGui::MenuItem("Close", "Ctrl+W")) { my_tool_activate = false; }
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	ImGui::End();
}

void resourceWindow::sizeWindow(int width, int height) {
	positionx = 0;
	positiony = height;
}

void resourceWindow::resourceWindowRender(int width, int height, int posy) {
	sizeWindow(width, posy);
	ImGui::SetNextWindowPos(ImVec2((float)positionx, (float)positiony));
	ImGui::SetNextWindowSize(ImVec2((float)width, (float)height));
	ImGui::Begin("resource");
	ImGui::Button("Hello!");
	if (ImGui::ImageButton(icon, ImVec2(sizeIconResource, sizeIconResource), ImVec2(0, 0), ImVec2(32.0f, 32.0f), 2, ImColor(0, 0, 0, 255))) {
		ImGui::ImageButton(icon, ImVec2(sizeIconResource, sizeIconResource), ImVec2(0, 0), ImVec2(32.0f, 32.0f), 2, ImColor(0, 0, 0, 255));
	}
	ImGui::SameLine();
	ImGui::ImageButton(icon, ImVec2(sizeIconResource, sizeIconResource), ImVec2(0, 0), ImVec2(32.0f, 32.0f), 2, ImColor(0, 0, 0, 255));
	ImGui::SameLine();
	ImGui::ImageButton(icon, ImVec2(sizeIconResource, sizeIconResource), ImVec2(0, 0), ImVec2(32.0f, 32.0f), 2, ImColor(0, 0, 0, 255));
	ImGui::End();
}


void GUI::menuRender() {
	glBegin(GL_TRIANGLES);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);
	glEnd();


	glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, data);
}

