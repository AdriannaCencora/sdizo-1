#include "stdafx.h"
#include "rbTreeController.h"

#include "../../views/rbTree/rbTreeMenu.h"
#include "../../structures/rbTree/rbTree.h"

void rbTreeController::init()
{
	structure = std::make_unique<rbTree>();
	menu = std::make_unique<rbTreeMenu>();
}