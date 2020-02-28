#include "../Scene.h"
#include "../SceneText.h"
#include "../../../glew/include/GL/glew.h"
#include "../Application.h"
#include "../Currency.h"
#include "../Inventory.h"

Currency* currency4 = Currency::GetInstance();

Inventory* inventory4 = Inventory::GetInstance();

void SceneText::RenderUI()
{
	RenderTextOnScreen(meshList[GEO_TEXT], currency4->ReturnAdjustedCurrency(), Color(0, 1, 0), 4, 15, 13);
	RenderTextOnScreen(meshList[GEO_TEXT], "QUESTS", Color(0, 1, 0), 3, 5, 1.5);

	if (npc[0].QuestIsActive() == true)
		RenderTextOnScreen(meshList[GEO_TEXT], npc[0].ReturnQuest()->ReturnRequirement(), Color(0, 1, 0), 3, 5, 0.5);
	else
		RenderTextOnScreen(meshList[GEO_TEXT], "No current quests.", Color(0, 1, 0), 3, 5, 0.5);

	if (!Application::IsKeyPressed('W')) {
		RenderMeshOnScreen(meshList[BUTTON_W], 10.f, 11.f, 6.5f, 6.5f);
	}
	else {
		RenderMeshOnScreen(meshList[BUTTON_W_HIGHLIGHT], 10.f, 11.f, 6.5f, 6.5f);
	}

	if (!Application::IsKeyPressed('A')) {
		RenderMeshOnScreen(meshList[BUTTON_A], 4.f, 5.f, 6.5f, 6.5f);
	}
	else {
		RenderMeshOnScreen(meshList[BUTTON_A_HIGHLIGHT], 4.f, 5.f, 6.5f, 6.5f);
	}

	if (!Application::IsKeyPressed('S')) {
		RenderMeshOnScreen(meshList[BUTTON_S], 10.f, 5.f, 6.5f, 6.5f);
	}
	else {
		RenderMeshOnScreen(meshList[BUTTON_S_HIGHLIGHT], 10.f, 5.f, 6.5f, 6.5f);
	}

	if (!Application::IsKeyPressed('D')) {
		RenderMeshOnScreen(meshList[BUTTON_D], 16.f, 5.f, 6.5f, 6.5f);
	}
	else {
		RenderMeshOnScreen(meshList[BUTTON_D_HIGHLIGHT], 16.f, 5.f, 6.5f, 6.5f);
	}

	if (!Application::IsKeyPressed(MK_LBUTTON)) {
		RenderMeshOnScreen(meshList[L_MOUSE], 70.f, 5.f, 6.5f, 6.5f);
	}
	else {
		RenderMeshOnScreen(meshList[L_MOUSE_HIGHLIGHT], 70.f, 5.f, 6.5f, 6.5f);
	}
}

void SceneText::RenderNPCUI(NPC npc)
{
	RenderTextOnScreen(meshList[GEO_TEXT], currency4->ReturnAdjustedCurrency(), Color(0, 1, 0), 4, 15, 13);

	RenderTextOnScreen(meshList[GEO_TEXT], "QUESTS", Color(0, 1, 0), 3, 5, 5.5);
	if (npc.QuestIsActive() == true)
		RenderTextOnScreen(meshList[GEO_TEXT], npc.ReturnQuest()->ReturnRequirement(), Color(0, 1, 0), 3, 5, 4.5);
	else
		RenderTextOnScreen(meshList[GEO_TEXT], "No current quests.", Color(0, 1, 0), 3, 5, 4.5);

	RenderMeshOnScreen(meshList[TEXT_BORDER], 40.f, 5.f, 100.f, 15.f);


	RenderTextOnScreen(meshList[GEO_TEXT], npc.ReturnDialogue(), Color(0, 1, 0), 3, 5, 2.5);

	RenderTextOnScreen(meshList[GEO_TEXT], "1. Talk", Color(0, 1, 0), 3, 5, 1.5);
	RenderTextOnScreen(meshList[GEO_TEXT], "2. Accept a quest", Color(0, 1, 0), 3, 5, 0.5);

	if (npc.IsGoingToGiveTip())
	{
		RenderText(meshList[GEO_TEXT], npc.ReturnTips(), Color(0, 1, 0), 0.4f, 0.f, 0.f, 0.f);
	}

}

void SceneText::RenderVendingUI()
{
	RenderTextOnScreen(meshList[GEO_TEXT], currency4->ReturnAdjustedCurrency(), Color(0, 1, 0), 4, 15, 13);

	if (!vending[0].BuyingItem()) {
		RenderTextOnScreen(meshList[GEO_TEXT], "What would you like to buy?", Color(0, 1, 0), 2.5f, 3.f, 2.f);
		RenderTextOnScreen(meshList[GEO_TEXT], vending[0].GetItemChosen(), Color(0, 1, 0), 3.5f, 12.f, 1.3f);
	}

	if (vending[0].BuyingItem()) {
		RenderTextOnScreen(meshList[GEO_TEXT], "Buy item " + vending[0].GetItemChosen() + " ?(Y/N)", Color(0, 1, 0), 3.5f, 2.2f, 1.3f);
		RenderMeshOnScreen(meshList[STEAK], 10.f, 10.f, 7.f, 5.f);
	}

	if (vending[0].ItemIsBought()) {
		RenderTextOnScreen(meshList[GEO_TEXT], "Item " + vending[0].GetItemIssued() + " bought.", Color(0, 1, 0), 2.3f, 2.2f, 22.f);
	}

}

void SceneText::RenderInventoryUI()
{
	float valY = 16.f;

	RenderTextOnScreen(meshList[GEO_TEXT], "INVENTORY: ", Color(0, 1, 0), 3.f, 1.f, valY + 1.f);
	for (int i = 1; i < inventory4->ReturnInventory().size() + 1; ++i)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], std::to_string(i) + ". " + inventory4->ReturnInventory().at(i - 1)->ReturnName(), Color(0, 1, 0), 3.f, 2.0f, valY);
		valY -= 1.f;
	}
}