#include "Client.h"
using namespace std;
using namespace System::Diagnostics;
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main()
{
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    client::Client form;
    Application::Run(% form);
    return 0;
}



