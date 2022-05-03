#include "Management.h"

int main()
{
	system("cls");

	std::string paths = "./Config.yaml";

	Management M;
	M.ManagementManage(paths);

	system("pause");

	return 0;
}