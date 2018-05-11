#include "stdafx.h"
#include "menu.h"

Menu::Menu()
{
	//D3DDEVICE_CREATION_PARAMETERS params;
	//d3dDevice9->GetCreationParameters(&params);

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize.x = 1920.0f;
	io.DisplaySize.y = 1080.0f;
	unsigned char* pixels;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);

	ImGui_ImplDX9_Init(GetActiveWindow(), d3dDevice9);

	visible = true;//false; //hide by default
}

Menu::~Menu()
{
	ImGui::DestroyContext();
	ImGui_ImplDX9_Shutdown();
}

void Menu::draw() {
	if (!isVisible()) {
		return;
	}

	ImGuiIO& io = ImGui::GetIO();

	RECT desktop;
	GetWindowRect(GetActiveWindow(), &desktop);
	if (desktop.right > 0 && desktop.bottom > 0) {
		io.DisplaySize.x = desktop.right;
		io.DisplaySize.y = desktop.bottom;
	}
	if (d3dDevice9->BeginScene() >= 0)
	{
		ImGui::NewFrame();
		ImGui_ImplDX9_NewFrame();

		ImGui::GetIO().MouseDrawCursor = isVisible();

		ImGui::SetNextWindowPos(ImVec2{ 0, 0 }, ImGuiSetCond_Once);
		ImGui::SetNextWindowSize(ImVec2{ 1000, 0 }, ImGuiSetCond_Once);

		ImGui::Begin("Robeth's Fun Menu", &visible, ImGuiWindowFlags_NoCollapse);
		ImGui::Button("Invert Gravity");
		ImGui::End();
		//ImGui::EndFrame();

		d3dDevice9->SetRenderState(D3DRS_ZENABLE, false);
		d3dDevice9->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		d3dDevice9->SetRenderState(D3DRS_SCISSORTESTENABLE, false);

		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		d3dDevice9->EndScene();
	}
}