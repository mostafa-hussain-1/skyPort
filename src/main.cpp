#include"UI/user_home_page.h"
#include"include/database.h"
using namespace std;
using namespace skyPort;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
    upload_database();
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew user_home_page());

    download_database();
	return 0;
}