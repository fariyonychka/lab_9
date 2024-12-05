#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <msclr/marshal_cppstd.h> // Для marshal_as
using namespace msclr::interop; 
bool continueSearch = true;
HANDLE hPipe = INVALID_HANDLE_VALUE;
LPCWSTR pipeName = L"\\\\.\\pipe\\MyPipe";
std::wstring directory;
std::wstring extension;
namespace client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Client
	/// </summary>
	public ref class Client : public System::Windows::Forms::Form
	{
	public:
		Client(void)
		{
			InitializeComponent();
			hPipe = CreateFile(pipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
			InitializeTimer(); 

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Client()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Timer^ connectionTimer;
	private: System::Windows::Forms::Label^ labelForConnecting;
	private: System::Windows::Forms::TextBox^ textBoxForDirectory;
	protected:



	private: System::Windows::Forms::Button^ buttonAddRequest;




	private: System::Windows::Forms::TextBox^ textBoxForLog;
	private: System::Windows::Forms::ComboBox^ comboBoxExtension;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelForConnecting = (gcnew System::Windows::Forms::Label());
			this->textBoxForDirectory = (gcnew System::Windows::Forms::TextBox());
			this->buttonAddRequest = (gcnew System::Windows::Forms::Button());
			this->textBoxForLog = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxExtension = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelForConnecting
			// 
			this->labelForConnecting->AutoSize = true;
			this->labelForConnecting->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelForConnecting->Location = System::Drawing::Point(12, 9);
			this->labelForConnecting->Name = L"labelForConnecting";
			this->labelForConnecting->Size = System::Drawing::Size(0, 16);
			this->labelForConnecting->TabIndex = 0;
			// 
			// textBoxForDirectory
			// 
			this->textBoxForDirectory->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F, System::Drawing::FontStyle::Bold));
			this->textBoxForDirectory->Location = System::Drawing::Point(15, 108);
			this->textBoxForDirectory->Multiline = true;
			this->textBoxForDirectory->Name = L"textBoxForDirectory";
			this->textBoxForDirectory->Size = System::Drawing::Size(199, 38);
			this->textBoxForDirectory->TabIndex = 1;
			// 
			// buttonAddRequest
			// 
			this->buttonAddRequest->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonAddRequest->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAddRequest->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonAddRequest->Location = System::Drawing::Point(12, 162);
			this->buttonAddRequest->Name = L"buttonAddRequest";
			this->buttonAddRequest->Size = System::Drawing::Size(309, 38);
			this->buttonAddRequest->TabIndex = 4;
			this->buttonAddRequest->Text = L"Request";
			this->buttonAddRequest->UseVisualStyleBackColor = false;
			this->buttonAddRequest->Click += gcnew System::EventHandler(this, &Client::buttonAddRequest_Click);
			// 
			// textBoxForLog
			// 
			this->textBoxForLog->BackColor = System::Drawing::Color::LightSteelBlue;
			this->textBoxForLog->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxForLog->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxForLog->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textBoxForLog->Location = System::Drawing::Point(381, 12);
			this->textBoxForLog->Multiline = true;
			this->textBoxForLog->Name = L"textBoxForLog";
			this->textBoxForLog->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxForLog->Size = System::Drawing::Size(723, 416);
			this->textBoxForLog->TabIndex = 7;
			// 
			// comboBoxExtension
			// 
			this->comboBoxExtension->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F, System::Drawing::FontStyle::Bold));
			this->comboBoxExtension->FormattingEnabled = true;
			this->comboBoxExtension->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L".txt", L".docx" });
			this->comboBoxExtension->Location = System::Drawing::Point(243, 116);
			this->comboBoxExtension->Name = L"comboBoxExtension";
			this->comboBoxExtension->Size = System::Drawing::Size(78, 30);
			this->comboBoxExtension->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(12, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(161, 16);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Enter directory path";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(240, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 16);
			this->label2->TabIndex = 10;
			this->label2->Text = L"File extension";
			// 
			// Client
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1116, 440);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxExtension);
			this->Controls->Add(this->textBoxForLog);
			this->Controls->Add(this->buttonAddRequest);
			this->Controls->Add(this->textBoxForDirectory);
			this->Controls->Add(this->labelForConnecting);
			this->Name = L"Client";
			this->Text = L"Client";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeConnection() {
			hPipe = CreateFile(pipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
			labelForConnecting->Text = "";

			if (hPipe == INVALID_HANDLE_VALUE) {
				labelForConnecting->Text = "Error connecting to server " + "\r\n";
			}
			else {
				labelForConnecting->Text = "Connected to server" + "\r\n";
			}
		}

		void InitializeTimer() {
			connectionTimer = gcnew System::Windows::Forms::Timer();
			connectionTimer->Interval = 5000; 
			connectionTimer->Tick += gcnew EventHandler(this, &Client::CheckConnection);
			connectionTimer->Start(); 
		}
#pragma endregion

		void SendRequestToServer(const std::wstring& directory, const std::wstring& extension, HANDLE hPipe) {
			std::wstring data = directory + L"|" + extension;
			if (!WriteFile(hPipe, data.c_str(), data.size() * sizeof(wchar_t), NULL, NULL)) {
				if (textBoxForLog->InvokeRequired) {
					textBoxForLog->Invoke(gcnew Action<System::String^>(this, &Client::UpdateLog), "Client: Error writing to pipe");
				}
				else {
					textBoxForLog->Text += "Client: Error writing to pipe" + "\r\n";
				}
			}
			else {
				if (textBoxForLog->InvokeRequired) {
					textBoxForLog->Invoke(gcnew Action<System::String^>(this, &Client::UpdateLog), gcnew String((L"Client: Sent request to server: " + data).c_str()));
				}
				else {
					textBoxForLog->Text += gcnew String((L"Client: Sent request to server: " + data).c_str()) + "\r\n";
				}
			}
		}

		void ReceiveFileListFromServer(HANDLE hPipe) {
			const DWORD bufferSize = 10000;
			WCHAR buffer[bufferSize];
			BOOL success;
			do {
				DWORD bytesRead;
				success = ReadFile(hPipe, buffer, sizeof(buffer), &bytesRead, NULL);
				if (!success || bytesRead == 0) {
					break;
				}
				std::wstring data(buffer, bytesRead / sizeof(WCHAR));

				// Перевіряємо, чи отримано повідомлення про завершення передачі
				if (data == L"EndOfFileList") {
					// Просто зупиняємо цикл без виведення повідомлення
					break;
				}
				else if (data.find(L"Server: Error") != std::wstring::npos) {
					// Виводимо тільки повідомлення про помилку
					if (textBoxForLog->InvokeRequired) {
						textBoxForLog->Invoke(gcnew Action<System::String^>(this, &Client::UpdateLog), gcnew String(data.c_str()));
					}
					else {
						textBoxForLog->Text += "\n" + gcnew String(data.c_str()) + "\r\n";
					}
				}
				else {
					// Виводимо всі інші повідомлення на екран
					if (textBoxForLog->InvokeRequired) {
						textBoxForLog->Invoke(gcnew Action<System::String^>(this, &Client::UpdateLog), gcnew String(data.c_str()));
					}
					else {
						textBoxForLog->Text += gcnew String(data.c_str()) + "\r\n";
					}
				}
			} while (success);
		}




	private: void CheckConnection(System::Object^ sender, System::EventArgs^ e) {
		if (hPipe == INVALID_HANDLE_VALUE) {
			InitializeConnection(); 
			return;
		}

		DWORD bytesWritten;
		BOOL writeResult = WriteFile(hPipe, NULL, 0, &bytesWritten, NULL);

		if (writeResult || GetLastError() == ERROR_PIPE_CONNECTED) {
			labelForConnecting->Text = "Connected to server..." + "\r\n";
		}
		else {
			labelForConnecting->Text = "Connection is disconnected..." + "\r\n";
			CloseHandle(hPipe); 
			hPipe = INVALID_HANDLE_VALUE; 
		}
	}

	private: System::Void UpdateLog(System::String^ message) {
		if (textBoxForLog->InvokeRequired) {
			textBoxForLog->Invoke(gcnew Action<System::String^>(this, &Client::UpdateLog), message);
		}
		else {
			textBoxForLog->AppendText(message + "\r\n");
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
}


private: System::Void buttonAddRequest_Click(System::Object^ sender, System::EventArgs^ e) {
	directory = msclr::interop::marshal_as<std::wstring>(textBoxForDirectory->Text);
	extension= msclr::interop::marshal_as<std::wstring>(comboBoxExtension->Text);
	SendRequestToServer(directory, extension, hPipe);
	ReceiveFileListFromServer(hPipe);
}
};
}
