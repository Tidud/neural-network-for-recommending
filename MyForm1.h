#pragma once
#include "MyForm.h"
#include "network.h"
#include <fstream>
#include <string>
namespace houses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
            int n = 3;
            int value = 100;
            float alpha = 0.08;
            float betta = 0.017;
            int layers[3] = { 10,6,1 };
            int pred[100];
            int examples[100][10];
            int price[100];
            std::ifstream file;
            file.open("data.txt");

            for (int i = 0; i < value; i++)
            {
                for (int j = 0; j < layers[0]; j++)
                {
                    file >> examples[i][j];

                }
            }
            std::ifstream file1;
            file1.open("price.txt");
            for (int i = 0; i < 100; i++)
            {
                file1 >> price[i];
            }
            nueral_network net;
            net.init(layers, n, alpha, betta);
            std::string names[10] = { "Количество комнат: ","Общая площадь: ","Этаж квартиры: ", "Количество этажей в доме: " , "Отделка: ", "Площадь кухни: " ,"Наличие балкона: ", "Образовательные учреждения поблизости: ","Транспортные остановки поблизости: "," Торговые точки поблизости: " };
            //	Заполнение характеристик
            for (int i = 0; i < 100; i++)
            {
                std::string a = "";
                String^ b = "";

                for (int j = 0; j < layers[0]; j++)
                {
                    if (j != 0 && j != 2)
                    {
                        if (examples[i][j] == 1)
                        {
                            a += names[j] + "есть" + "  ";
                        }
                        else if (examples[i][j] == 0)
                        {
                            a += names[j] + "нет" + "  ";
                        }
                        else if (j == 1 || j == 5)
                        {
                            a += names[j] + std::to_string(examples[i][j]) + " " + "м2" + "\n ";
                        }
                        else
                        {
                            a += names[j] + std::to_string(examples[i][j]) + "  ";
                        }
                    }
                    else
                    {
                        a += names[j] + std::to_string(examples[i][j]) + "  ";
                    }

                    b = gcnew System::String(a.c_str());
                }

                Controls["label" + Convert::ToString((i * 2) + 1)]->Text = b;
            }

            // Заполнение цен
            for (int i = 1; i < 101; i++)
            {
                String^ a = "";
                a += Convert::ToString(price[i - 1]) + "  ";

                Controls["label" + Convert::ToString(i * 2)]->Text = a;
            }
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
private: System::Windows::Forms::Button^ buttonclose;
private: System::Windows::Forms::Button^ buttonexit;
private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::CheckBox^ checkBox6;
    private: System::Windows::Forms::Label^ label11;

    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::CheckBox^ checkBox7;
    private: System::Windows::Forms::Label^ label13;

    private: System::Windows::Forms::Label^ label14;
    private: System::Windows::Forms::CheckBox^ checkBox8;
    private: System::Windows::Forms::Label^ label15;

    private: System::Windows::Forms::Label^ label16;
    private: System::Windows::Forms::CheckBox^ checkBox9;
    private: System::Windows::Forms::Label^ label17;

    private: System::Windows::Forms::Label^ label18;
    private: System::Windows::Forms::CheckBox^ checkBox10;
    private: System::Windows::Forms::Label^ label19;

    private: System::Windows::Forms::Label^ label20;
    private: System::Windows::Forms::CheckBox^ checkBox11;
    private: System::Windows::Forms::Label^ label21;

    private: System::Windows::Forms::Label^ label22;
    private: System::Windows::Forms::CheckBox^ checkBox12;
    private: System::Windows::Forms::Label^ label23;

    private: System::Windows::Forms::Label^ label24;
    private: System::Windows::Forms::CheckBox^ checkBox13;
    private: System::Windows::Forms::Label^ label25;

    private: System::Windows::Forms::Label^ label26;
    private: System::Windows::Forms::CheckBox^ checkBox14;
    private: System::Windows::Forms::Label^ label27;

    private: System::Windows::Forms::Label^ label28;
    private: System::Windows::Forms::CheckBox^ checkBox15;
    private: System::Windows::Forms::Label^ label29;

    private: System::Windows::Forms::Label^ label30;
    private: System::Windows::Forms::CheckBox^ checkBox16;
    private: System::Windows::Forms::Label^ label31;

    private: System::Windows::Forms::Label^ label32;
    private: System::Windows::Forms::CheckBox^ checkBox17;
    private: System::Windows::Forms::Label^ label33;

    private: System::Windows::Forms::Label^ label34;
    private: System::Windows::Forms::CheckBox^ checkBox18;
    private: System::Windows::Forms::Label^ label35;

    private: System::Windows::Forms::Label^ label36;
    private: System::Windows::Forms::CheckBox^ checkBox19;
    private: System::Windows::Forms::Label^ label37;

    private: System::Windows::Forms::Label^ label38;
    private: System::Windows::Forms::CheckBox^ checkBox20;
    private: System::Windows::Forms::Label^ label39;

    private: System::Windows::Forms::Label^ label40;
    private: System::Windows::Forms::CheckBox^ checkBox21;
    private: System::Windows::Forms::Label^ label41;

    private: System::Windows::Forms::Label^ label42;
    private: System::Windows::Forms::CheckBox^ checkBox22;
    private: System::Windows::Forms::Label^ label43;

    private: System::Windows::Forms::Label^ label44;
    private: System::Windows::Forms::CheckBox^ checkBox23;
    private: System::Windows::Forms::Label^ label45;

    private: System::Windows::Forms::Label^ label46;
    private: System::Windows::Forms::CheckBox^ checkBox24;
    private: System::Windows::Forms::Label^ label47;

    private: System::Windows::Forms::Label^ label48;
    private: System::Windows::Forms::CheckBox^ checkBox25;
    private: System::Windows::Forms::Label^ label49;

    private: System::Windows::Forms::Label^ label50;
    private: System::Windows::Forms::CheckBox^ checkBox26;
    private: System::Windows::Forms::Label^ label51;

    private: System::Windows::Forms::Label^ label52;
    private: System::Windows::Forms::CheckBox^ checkBox27;
    private: System::Windows::Forms::Label^ label53;

    private: System::Windows::Forms::Label^ label54;
    private: System::Windows::Forms::CheckBox^ checkBox28;
    private: System::Windows::Forms::Label^ label55;

    private: System::Windows::Forms::Label^ label56;
    private: System::Windows::Forms::CheckBox^ checkBox29;
    private: System::Windows::Forms::Label^ label57;

    private: System::Windows::Forms::Label^ label58;
    private: System::Windows::Forms::CheckBox^ checkBox30;
    private: System::Windows::Forms::Label^ label59;

    private: System::Windows::Forms::Label^ label60;
    private: System::Windows::Forms::CheckBox^ checkBox31;
    private: System::Windows::Forms::Label^ label61;

    private: System::Windows::Forms::Label^ label62;
    private: System::Windows::Forms::CheckBox^ checkBox32;
    private: System::Windows::Forms::Label^ label63;

    private: System::Windows::Forms::Label^ label64;
    private: System::Windows::Forms::CheckBox^ checkBox33;
    private: System::Windows::Forms::Label^ label65;

    private: System::Windows::Forms::Label^ label66;
    private: System::Windows::Forms::CheckBox^ checkBox34;
    private: System::Windows::Forms::Label^ label67;

    private: System::Windows::Forms::Label^ label68;
private: System::Windows::Forms::CheckBox^ checkBox35;
private: System::Windows::Forms::Label^ label69;

private: System::Windows::Forms::Label^ label70;
private: System::Windows::Forms::CheckBox^ checkBox36;
private: System::Windows::Forms::Label^ label71;

private: System::Windows::Forms::Label^ label72;
private: System::Windows::Forms::CheckBox^ checkBox37;
private: System::Windows::Forms::Label^ label73;

private: System::Windows::Forms::Label^ label74;
private: System::Windows::Forms::CheckBox^ checkBox38;
private: System::Windows::Forms::Label^ label75;

private: System::Windows::Forms::Label^ label76;
private: System::Windows::Forms::CheckBox^ checkBox39;
private: System::Windows::Forms::Label^ label77;

private: System::Windows::Forms::Label^ label78;
private: System::Windows::Forms::CheckBox^ checkBox40;
private: System::Windows::Forms::Label^ label79;

private: System::Windows::Forms::Label^ label80;
private: System::Windows::Forms::CheckBox^ checkBox41;
private: System::Windows::Forms::Label^ label81;

private: System::Windows::Forms::Label^ label82;
private: System::Windows::Forms::CheckBox^ checkBox42;
private: System::Windows::Forms::Label^ label83;

private: System::Windows::Forms::Label^ label84;
private: System::Windows::Forms::CheckBox^ checkBox43;
private: System::Windows::Forms::Label^ label85;

private: System::Windows::Forms::Label^ label86;
private: System::Windows::Forms::CheckBox^ checkBox44;
private: System::Windows::Forms::Label^ label87;

private: System::Windows::Forms::Label^ label88;
private: System::Windows::Forms::CheckBox^ checkBox45;
private: System::Windows::Forms::Label^ label89;

private: System::Windows::Forms::Label^ label90;
private: System::Windows::Forms::CheckBox^ checkBox46;
private: System::Windows::Forms::Label^ label91;

private: System::Windows::Forms::Label^ label92;
private: System::Windows::Forms::CheckBox^ checkBox47;
private: System::Windows::Forms::Label^ label93;

private: System::Windows::Forms::Label^ label94;
private: System::Windows::Forms::CheckBox^ checkBox48;
private: System::Windows::Forms::Label^ label95;

private: System::Windows::Forms::Label^ label96;
private: System::Windows::Forms::CheckBox^ checkBox49;
private: System::Windows::Forms::Label^ label97;

private: System::Windows::Forms::Label^ label98;
private: System::Windows::Forms::CheckBox^ checkBox50;
private: System::Windows::Forms::Label^ label99;

private: System::Windows::Forms::Label^ label100;
private: System::Windows::Forms::CheckBox^ checkBox51;
private: System::Windows::Forms::Label^ label101;

private: System::Windows::Forms::Label^ label102;
private: System::Windows::Forms::CheckBox^ checkBox52;
private: System::Windows::Forms::Label^ label103;

private: System::Windows::Forms::Label^ label104;
private: System::Windows::Forms::CheckBox^ checkBox53;
private: System::Windows::Forms::Label^ label105;

private: System::Windows::Forms::Label^ label106;
private: System::Windows::Forms::CheckBox^ checkBox54;
private: System::Windows::Forms::Label^ label107;

private: System::Windows::Forms::Label^ label108;
private: System::Windows::Forms::CheckBox^ checkBox55;
private: System::Windows::Forms::Label^ label109;

private: System::Windows::Forms::Label^ label110;
private: System::Windows::Forms::CheckBox^ checkBox56;
private: System::Windows::Forms::Label^ label111;

private: System::Windows::Forms::Label^ label112;
private: System::Windows::Forms::CheckBox^ checkBox57;
private: System::Windows::Forms::Label^ label113;

private: System::Windows::Forms::Label^ label114;
private: System::Windows::Forms::CheckBox^ checkBox58;
private: System::Windows::Forms::Label^ label115;

private: System::Windows::Forms::Label^ label116;
private: System::Windows::Forms::CheckBox^ checkBox59;
private: System::Windows::Forms::Label^ label117;

private: System::Windows::Forms::Label^ label118;
private: System::Windows::Forms::CheckBox^ checkBox60;
private: System::Windows::Forms::Label^ label119;

private: System::Windows::Forms::Label^ label120;
private: System::Windows::Forms::CheckBox^ checkBox61;
private: System::Windows::Forms::Label^ label121;

private: System::Windows::Forms::Label^ label122;
private: System::Windows::Forms::CheckBox^ checkBox62;
private: System::Windows::Forms::Label^ label123;

private: System::Windows::Forms::Label^ label124;
private: System::Windows::Forms::CheckBox^ checkBox63;
private: System::Windows::Forms::Label^ label125;

private: System::Windows::Forms::Label^ label126;
private: System::Windows::Forms::CheckBox^ checkBox64;
private: System::Windows::Forms::Label^ label127;

private: System::Windows::Forms::Label^ label128;
private: System::Windows::Forms::CheckBox^ checkBox65;
private: System::Windows::Forms::Label^ label129;

private: System::Windows::Forms::Label^ label130;
private: System::Windows::Forms::CheckBox^ checkBox66;
private: System::Windows::Forms::Label^ label131;

private: System::Windows::Forms::Label^ label132;
private: System::Windows::Forms::CheckBox^ checkBox67;
private: System::Windows::Forms::Label^ label133;

private: System::Windows::Forms::Label^ label134;
private: System::Windows::Forms::CheckBox^ checkBox68;
private: System::Windows::Forms::Label^ label135;

private: System::Windows::Forms::Label^ label136;
private: System::Windows::Forms::CheckBox^ checkBox69;
private: System::Windows::Forms::Label^ label137;

private: System::Windows::Forms::Label^ label138;
private: System::Windows::Forms::CheckBox^ checkBox70;
private: System::Windows::Forms::Label^ label139;

private: System::Windows::Forms::Label^ label140;
private: System::Windows::Forms::CheckBox^ checkBox71;
private: System::Windows::Forms::Label^ label141;

private: System::Windows::Forms::Label^ label142;
private: System::Windows::Forms::CheckBox^ checkBox72;
private: System::Windows::Forms::Label^ label143;

private: System::Windows::Forms::Label^ label144;
private: System::Windows::Forms::CheckBox^ checkBox73;
private: System::Windows::Forms::Label^ label145;

private: System::Windows::Forms::Label^ label146;
private: System::Windows::Forms::CheckBox^ checkBox74;
private: System::Windows::Forms::Label^ label147;

private: System::Windows::Forms::Label^ label148;
private: System::Windows::Forms::CheckBox^ checkBox75;
private: System::Windows::Forms::Label^ label149;

private: System::Windows::Forms::Label^ label150;
private: System::Windows::Forms::CheckBox^ checkBox76;
private: System::Windows::Forms::Label^ label151;

private: System::Windows::Forms::Label^ label152;
private: System::Windows::Forms::CheckBox^ checkBox77;
private: System::Windows::Forms::Label^ label153;

private: System::Windows::Forms::Label^ label154;
private: System::Windows::Forms::CheckBox^ checkBox78;
private: System::Windows::Forms::Label^ label155;

private: System::Windows::Forms::Label^ label156;
private: System::Windows::Forms::CheckBox^ checkBox79;
private: System::Windows::Forms::Label^ label157;

private: System::Windows::Forms::Label^ label158;
private: System::Windows::Forms::CheckBox^ checkBox80;
private: System::Windows::Forms::Label^ label159;

private: System::Windows::Forms::Label^ label160;
private: System::Windows::Forms::CheckBox^ checkBox81;
private: System::Windows::Forms::Label^ label161;

private: System::Windows::Forms::Label^ label162;
private: System::Windows::Forms::CheckBox^ checkBox82;
private: System::Windows::Forms::Label^ label163;

private: System::Windows::Forms::Label^ label164;
private: System::Windows::Forms::CheckBox^ checkBox83;
private: System::Windows::Forms::Label^ label165;

private: System::Windows::Forms::Label^ label166;
private: System::Windows::Forms::CheckBox^ checkBox84;
private: System::Windows::Forms::Label^ label167;

private: System::Windows::Forms::Label^ label168;
private: System::Windows::Forms::CheckBox^ checkBox85;
private: System::Windows::Forms::Label^ label169;

private: System::Windows::Forms::Label^ label170;
private: System::Windows::Forms::CheckBox^ checkBox86;
private: System::Windows::Forms::Label^ label171;

private: System::Windows::Forms::Label^ label172;
private: System::Windows::Forms::CheckBox^ checkBox87;
private: System::Windows::Forms::Label^ label173;

private: System::Windows::Forms::Label^ label174;
private: System::Windows::Forms::CheckBox^ checkBox88;
private: System::Windows::Forms::Label^ label175;

private: System::Windows::Forms::Label^ label176;
private: System::Windows::Forms::CheckBox^ checkBox89;
private: System::Windows::Forms::Label^ label177;

private: System::Windows::Forms::Label^ label178;
private: System::Windows::Forms::CheckBox^ checkBox90;
private: System::Windows::Forms::Label^ label179;

private: System::Windows::Forms::Label^ label180;
private: System::Windows::Forms::CheckBox^ checkBox91;
private: System::Windows::Forms::Label^ label181;

private: System::Windows::Forms::Label^ label182;
private: System::Windows::Forms::CheckBox^ checkBox92;
private: System::Windows::Forms::Label^ label183;

private: System::Windows::Forms::Label^ label184;
private: System::Windows::Forms::CheckBox^ checkBox93;
private: System::Windows::Forms::Label^ label185;

private: System::Windows::Forms::Label^ label186;
private: System::Windows::Forms::CheckBox^ checkBox94;
private: System::Windows::Forms::Label^ label187;

private: System::Windows::Forms::Label^ label188;
private: System::Windows::Forms::CheckBox^ checkBox95;
private: System::Windows::Forms::Label^ label189;

private: System::Windows::Forms::Label^ label190;
private: System::Windows::Forms::CheckBox^ checkBox96;
private: System::Windows::Forms::Label^ label191;

private: System::Windows::Forms::Label^ label192;
private: System::Windows::Forms::CheckBox^ checkBox97;
private: System::Windows::Forms::Label^ label193;

private: System::Windows::Forms::Label^ label194;
private: System::Windows::Forms::CheckBox^ checkBox98;
private: System::Windows::Forms::Label^ label195;

private: System::Windows::Forms::Label^ label196;
private: System::Windows::Forms::CheckBox^ checkBox99;
private: System::Windows::Forms::Label^ label197;

private: System::Windows::Forms::Label^ label198;
private: System::Windows::Forms::CheckBox^ checkBox100;
private: System::Windows::Forms::Label^ label199;

private: System::Windows::Forms::Label^ label200;
private: System::Windows::Forms::CheckBox^ checkBox1;



public: void changePicturePos(int i, int j);

	protected:


	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
            this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
            this->buttonclose = (gcnew System::Windows::Forms::Button());
            this->buttonexit = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->checkBox13 = (gcnew System::Windows::Forms::CheckBox());
            this->label25 = (gcnew System::Windows::Forms::Label());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->checkBox14 = (gcnew System::Windows::Forms::CheckBox());
            this->label27 = (gcnew System::Windows::Forms::Label());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->checkBox15 = (gcnew System::Windows::Forms::CheckBox());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->checkBox16 = (gcnew System::Windows::Forms::CheckBox());
            this->label31 = (gcnew System::Windows::Forms::Label());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->checkBox17 = (gcnew System::Windows::Forms::CheckBox());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->label34 = (gcnew System::Windows::Forms::Label());
            this->checkBox18 = (gcnew System::Windows::Forms::CheckBox());
            this->label35 = (gcnew System::Windows::Forms::Label());
            this->label36 = (gcnew System::Windows::Forms::Label());
            this->checkBox19 = (gcnew System::Windows::Forms::CheckBox());
            this->label37 = (gcnew System::Windows::Forms::Label());
            this->label38 = (gcnew System::Windows::Forms::Label());
            this->checkBox20 = (gcnew System::Windows::Forms::CheckBox());
            this->label39 = (gcnew System::Windows::Forms::Label());
            this->label40 = (gcnew System::Windows::Forms::Label());
            this->checkBox21 = (gcnew System::Windows::Forms::CheckBox());
            this->label41 = (gcnew System::Windows::Forms::Label());
            this->label42 = (gcnew System::Windows::Forms::Label());
            this->checkBox22 = (gcnew System::Windows::Forms::CheckBox());
            this->label43 = (gcnew System::Windows::Forms::Label());
            this->label44 = (gcnew System::Windows::Forms::Label());
            this->checkBox23 = (gcnew System::Windows::Forms::CheckBox());
            this->label45 = (gcnew System::Windows::Forms::Label());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->checkBox24 = (gcnew System::Windows::Forms::CheckBox());
            this->label47 = (gcnew System::Windows::Forms::Label());
            this->label48 = (gcnew System::Windows::Forms::Label());
            this->checkBox25 = (gcnew System::Windows::Forms::CheckBox());
            this->label49 = (gcnew System::Windows::Forms::Label());
            this->label50 = (gcnew System::Windows::Forms::Label());
            this->checkBox26 = (gcnew System::Windows::Forms::CheckBox());
            this->label51 = (gcnew System::Windows::Forms::Label());
            this->label52 = (gcnew System::Windows::Forms::Label());
            this->checkBox27 = (gcnew System::Windows::Forms::CheckBox());
            this->label53 = (gcnew System::Windows::Forms::Label());
            this->label54 = (gcnew System::Windows::Forms::Label());
            this->checkBox28 = (gcnew System::Windows::Forms::CheckBox());
            this->label55 = (gcnew System::Windows::Forms::Label());
            this->label56 = (gcnew System::Windows::Forms::Label());
            this->checkBox29 = (gcnew System::Windows::Forms::CheckBox());
            this->label57 = (gcnew System::Windows::Forms::Label());
            this->label58 = (gcnew System::Windows::Forms::Label());
            this->checkBox30 = (gcnew System::Windows::Forms::CheckBox());
            this->label59 = (gcnew System::Windows::Forms::Label());
            this->label60 = (gcnew System::Windows::Forms::Label());
            this->checkBox31 = (gcnew System::Windows::Forms::CheckBox());
            this->label61 = (gcnew System::Windows::Forms::Label());
            this->label62 = (gcnew System::Windows::Forms::Label());
            this->checkBox32 = (gcnew System::Windows::Forms::CheckBox());
            this->label63 = (gcnew System::Windows::Forms::Label());
            this->label64 = (gcnew System::Windows::Forms::Label());
            this->checkBox33 = (gcnew System::Windows::Forms::CheckBox());
            this->label65 = (gcnew System::Windows::Forms::Label());
            this->label66 = (gcnew System::Windows::Forms::Label());
            this->checkBox34 = (gcnew System::Windows::Forms::CheckBox());
            this->label67 = (gcnew System::Windows::Forms::Label());
            this->label68 = (gcnew System::Windows::Forms::Label());
            this->checkBox35 = (gcnew System::Windows::Forms::CheckBox());
            this->label69 = (gcnew System::Windows::Forms::Label());
            this->label70 = (gcnew System::Windows::Forms::Label());
            this->checkBox36 = (gcnew System::Windows::Forms::CheckBox());
            this->label71 = (gcnew System::Windows::Forms::Label());
            this->label72 = (gcnew System::Windows::Forms::Label());
            this->checkBox37 = (gcnew System::Windows::Forms::CheckBox());
            this->label73 = (gcnew System::Windows::Forms::Label());
            this->label74 = (gcnew System::Windows::Forms::Label());
            this->checkBox38 = (gcnew System::Windows::Forms::CheckBox());
            this->label75 = (gcnew System::Windows::Forms::Label());
            this->label76 = (gcnew System::Windows::Forms::Label());
            this->checkBox39 = (gcnew System::Windows::Forms::CheckBox());
            this->label77 = (gcnew System::Windows::Forms::Label());
            this->label78 = (gcnew System::Windows::Forms::Label());
            this->checkBox40 = (gcnew System::Windows::Forms::CheckBox());
            this->label79 = (gcnew System::Windows::Forms::Label());
            this->label80 = (gcnew System::Windows::Forms::Label());
            this->checkBox41 = (gcnew System::Windows::Forms::CheckBox());
            this->label81 = (gcnew System::Windows::Forms::Label());
            this->label82 = (gcnew System::Windows::Forms::Label());
            this->checkBox42 = (gcnew System::Windows::Forms::CheckBox());
            this->label83 = (gcnew System::Windows::Forms::Label());
            this->label84 = (gcnew System::Windows::Forms::Label());
            this->checkBox43 = (gcnew System::Windows::Forms::CheckBox());
            this->label85 = (gcnew System::Windows::Forms::Label());
            this->label86 = (gcnew System::Windows::Forms::Label());
            this->checkBox44 = (gcnew System::Windows::Forms::CheckBox());
            this->label87 = (gcnew System::Windows::Forms::Label());
            this->label88 = (gcnew System::Windows::Forms::Label());
            this->checkBox45 = (gcnew System::Windows::Forms::CheckBox());
            this->label89 = (gcnew System::Windows::Forms::Label());
            this->label90 = (gcnew System::Windows::Forms::Label());
            this->checkBox46 = (gcnew System::Windows::Forms::CheckBox());
            this->label91 = (gcnew System::Windows::Forms::Label());
            this->label92 = (gcnew System::Windows::Forms::Label());
            this->checkBox47 = (gcnew System::Windows::Forms::CheckBox());
            this->label93 = (gcnew System::Windows::Forms::Label());
            this->label94 = (gcnew System::Windows::Forms::Label());
            this->checkBox48 = (gcnew System::Windows::Forms::CheckBox());
            this->label95 = (gcnew System::Windows::Forms::Label());
            this->label96 = (gcnew System::Windows::Forms::Label());
            this->checkBox49 = (gcnew System::Windows::Forms::CheckBox());
            this->label97 = (gcnew System::Windows::Forms::Label());
            this->label98 = (gcnew System::Windows::Forms::Label());
            this->checkBox50 = (gcnew System::Windows::Forms::CheckBox());
            this->label99 = (gcnew System::Windows::Forms::Label());
            this->label100 = (gcnew System::Windows::Forms::Label());
            this->checkBox51 = (gcnew System::Windows::Forms::CheckBox());
            this->label101 = (gcnew System::Windows::Forms::Label());
            this->label102 = (gcnew System::Windows::Forms::Label());
            this->checkBox52 = (gcnew System::Windows::Forms::CheckBox());
            this->label103 = (gcnew System::Windows::Forms::Label());
            this->label104 = (gcnew System::Windows::Forms::Label());
            this->checkBox53 = (gcnew System::Windows::Forms::CheckBox());
            this->label105 = (gcnew System::Windows::Forms::Label());
            this->label106 = (gcnew System::Windows::Forms::Label());
            this->checkBox54 = (gcnew System::Windows::Forms::CheckBox());
            this->label107 = (gcnew System::Windows::Forms::Label());
            this->label108 = (gcnew System::Windows::Forms::Label());
            this->checkBox55 = (gcnew System::Windows::Forms::CheckBox());
            this->label109 = (gcnew System::Windows::Forms::Label());
            this->label110 = (gcnew System::Windows::Forms::Label());
            this->checkBox56 = (gcnew System::Windows::Forms::CheckBox());
            this->label111 = (gcnew System::Windows::Forms::Label());
            this->label112 = (gcnew System::Windows::Forms::Label());
            this->checkBox57 = (gcnew System::Windows::Forms::CheckBox());
            this->label113 = (gcnew System::Windows::Forms::Label());
            this->label114 = (gcnew System::Windows::Forms::Label());
            this->checkBox58 = (gcnew System::Windows::Forms::CheckBox());
            this->label115 = (gcnew System::Windows::Forms::Label());
            this->label116 = (gcnew System::Windows::Forms::Label());
            this->checkBox59 = (gcnew System::Windows::Forms::CheckBox());
            this->label117 = (gcnew System::Windows::Forms::Label());
            this->label118 = (gcnew System::Windows::Forms::Label());
            this->checkBox60 = (gcnew System::Windows::Forms::CheckBox());
            this->label119 = (gcnew System::Windows::Forms::Label());
            this->label120 = (gcnew System::Windows::Forms::Label());
            this->checkBox61 = (gcnew System::Windows::Forms::CheckBox());
            this->label121 = (gcnew System::Windows::Forms::Label());
            this->label122 = (gcnew System::Windows::Forms::Label());
            this->checkBox62 = (gcnew System::Windows::Forms::CheckBox());
            this->label123 = (gcnew System::Windows::Forms::Label());
            this->label124 = (gcnew System::Windows::Forms::Label());
            this->checkBox63 = (gcnew System::Windows::Forms::CheckBox());
            this->label125 = (gcnew System::Windows::Forms::Label());
            this->label126 = (gcnew System::Windows::Forms::Label());
            this->checkBox64 = (gcnew System::Windows::Forms::CheckBox());
            this->label127 = (gcnew System::Windows::Forms::Label());
            this->label128 = (gcnew System::Windows::Forms::Label());
            this->checkBox65 = (gcnew System::Windows::Forms::CheckBox());
            this->label129 = (gcnew System::Windows::Forms::Label());
            this->label130 = (gcnew System::Windows::Forms::Label());
            this->checkBox66 = (gcnew System::Windows::Forms::CheckBox());
            this->label131 = (gcnew System::Windows::Forms::Label());
            this->label132 = (gcnew System::Windows::Forms::Label());
            this->checkBox67 = (gcnew System::Windows::Forms::CheckBox());
            this->label133 = (gcnew System::Windows::Forms::Label());
            this->label134 = (gcnew System::Windows::Forms::Label());
            this->checkBox68 = (gcnew System::Windows::Forms::CheckBox());
            this->label135 = (gcnew System::Windows::Forms::Label());
            this->label136 = (gcnew System::Windows::Forms::Label());
            this->checkBox69 = (gcnew System::Windows::Forms::CheckBox());
            this->label137 = (gcnew System::Windows::Forms::Label());
            this->label138 = (gcnew System::Windows::Forms::Label());
            this->checkBox70 = (gcnew System::Windows::Forms::CheckBox());
            this->label139 = (gcnew System::Windows::Forms::Label());
            this->label140 = (gcnew System::Windows::Forms::Label());
            this->checkBox71 = (gcnew System::Windows::Forms::CheckBox());
            this->label141 = (gcnew System::Windows::Forms::Label());
            this->label142 = (gcnew System::Windows::Forms::Label());
            this->checkBox72 = (gcnew System::Windows::Forms::CheckBox());
            this->label143 = (gcnew System::Windows::Forms::Label());
            this->label144 = (gcnew System::Windows::Forms::Label());
            this->checkBox73 = (gcnew System::Windows::Forms::CheckBox());
            this->label145 = (gcnew System::Windows::Forms::Label());
            this->label146 = (gcnew System::Windows::Forms::Label());
            this->checkBox74 = (gcnew System::Windows::Forms::CheckBox());
            this->label147 = (gcnew System::Windows::Forms::Label());
            this->label148 = (gcnew System::Windows::Forms::Label());
            this->checkBox75 = (gcnew System::Windows::Forms::CheckBox());
            this->label149 = (gcnew System::Windows::Forms::Label());
            this->label150 = (gcnew System::Windows::Forms::Label());
            this->checkBox76 = (gcnew System::Windows::Forms::CheckBox());
            this->label151 = (gcnew System::Windows::Forms::Label());
            this->label152 = (gcnew System::Windows::Forms::Label());
            this->checkBox77 = (gcnew System::Windows::Forms::CheckBox());
            this->label153 = (gcnew System::Windows::Forms::Label());
            this->label154 = (gcnew System::Windows::Forms::Label());
            this->checkBox78 = (gcnew System::Windows::Forms::CheckBox());
            this->label155 = (gcnew System::Windows::Forms::Label());
            this->label156 = (gcnew System::Windows::Forms::Label());
            this->checkBox79 = (gcnew System::Windows::Forms::CheckBox());
            this->label157 = (gcnew System::Windows::Forms::Label());
            this->label158 = (gcnew System::Windows::Forms::Label());
            this->checkBox80 = (gcnew System::Windows::Forms::CheckBox());
            this->label159 = (gcnew System::Windows::Forms::Label());
            this->label160 = (gcnew System::Windows::Forms::Label());
            this->checkBox81 = (gcnew System::Windows::Forms::CheckBox());
            this->label161 = (gcnew System::Windows::Forms::Label());
            this->label162 = (gcnew System::Windows::Forms::Label());
            this->checkBox82 = (gcnew System::Windows::Forms::CheckBox());
            this->label163 = (gcnew System::Windows::Forms::Label());
            this->label164 = (gcnew System::Windows::Forms::Label());
            this->checkBox83 = (gcnew System::Windows::Forms::CheckBox());
            this->label165 = (gcnew System::Windows::Forms::Label());
            this->label166 = (gcnew System::Windows::Forms::Label());
            this->checkBox84 = (gcnew System::Windows::Forms::CheckBox());
            this->label167 = (gcnew System::Windows::Forms::Label());
            this->label168 = (gcnew System::Windows::Forms::Label());
            this->checkBox85 = (gcnew System::Windows::Forms::CheckBox());
            this->label169 = (gcnew System::Windows::Forms::Label());
            this->label170 = (gcnew System::Windows::Forms::Label());
            this->checkBox86 = (gcnew System::Windows::Forms::CheckBox());
            this->label171 = (gcnew System::Windows::Forms::Label());
            this->label172 = (gcnew System::Windows::Forms::Label());
            this->checkBox87 = (gcnew System::Windows::Forms::CheckBox());
            this->label173 = (gcnew System::Windows::Forms::Label());
            this->label174 = (gcnew System::Windows::Forms::Label());
            this->checkBox88 = (gcnew System::Windows::Forms::CheckBox());
            this->label175 = (gcnew System::Windows::Forms::Label());
            this->label176 = (gcnew System::Windows::Forms::Label());
            this->checkBox89 = (gcnew System::Windows::Forms::CheckBox());
            this->label177 = (gcnew System::Windows::Forms::Label());
            this->label178 = (gcnew System::Windows::Forms::Label());
            this->checkBox90 = (gcnew System::Windows::Forms::CheckBox());
            this->label179 = (gcnew System::Windows::Forms::Label());
            this->label180 = (gcnew System::Windows::Forms::Label());
            this->checkBox91 = (gcnew System::Windows::Forms::CheckBox());
            this->label181 = (gcnew System::Windows::Forms::Label());
            this->label182 = (gcnew System::Windows::Forms::Label());
            this->checkBox92 = (gcnew System::Windows::Forms::CheckBox());
            this->label183 = (gcnew System::Windows::Forms::Label());
            this->label184 = (gcnew System::Windows::Forms::Label());
            this->checkBox93 = (gcnew System::Windows::Forms::CheckBox());
            this->label185 = (gcnew System::Windows::Forms::Label());
            this->label186 = (gcnew System::Windows::Forms::Label());
            this->checkBox94 = (gcnew System::Windows::Forms::CheckBox());
            this->label187 = (gcnew System::Windows::Forms::Label());
            this->label188 = (gcnew System::Windows::Forms::Label());
            this->checkBox95 = (gcnew System::Windows::Forms::CheckBox());
            this->label189 = (gcnew System::Windows::Forms::Label());
            this->label190 = (gcnew System::Windows::Forms::Label());
            this->checkBox96 = (gcnew System::Windows::Forms::CheckBox());
            this->label191 = (gcnew System::Windows::Forms::Label());
            this->label192 = (gcnew System::Windows::Forms::Label());
            this->checkBox97 = (gcnew System::Windows::Forms::CheckBox());
            this->label193 = (gcnew System::Windows::Forms::Label());
            this->label194 = (gcnew System::Windows::Forms::Label());
            this->checkBox98 = (gcnew System::Windows::Forms::CheckBox());
            this->label195 = (gcnew System::Windows::Forms::Label());
            this->label196 = (gcnew System::Windows::Forms::Label());
            this->checkBox99 = (gcnew System::Windows::Forms::CheckBox());
            this->label197 = (gcnew System::Windows::Forms::Label());
            this->label198 = (gcnew System::Windows::Forms::Label());
            this->checkBox100 = (gcnew System::Windows::Forms::CheckBox());
            this->label199 = (gcnew System::Windows::Forms::Label());
            this->label200 = (gcnew System::Windows::Forms::Label());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->SuspendLayout();
            // 
            // buttonclose
            // 
            this->buttonclose->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->buttonclose->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->buttonclose->Location = System::Drawing::Point(2, 0);
            this->buttonclose->Name = L"buttonclose";
            this->buttonclose->Size = System::Drawing::Size(100, 30);
            this->buttonclose->TabIndex = 0;
            this->buttonclose->Text = L"Назад";
            this->buttonclose->UseVisualStyleBackColor = false;
            this->buttonclose->Click += gcnew System::EventHandler(this, &MyForm1::buttonclose_Click);
            // 
            // buttonexit
            // 
            this->buttonexit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->buttonexit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->buttonexit->Location = System::Drawing::Point(108, 0);
            this->buttonexit->Name = L"buttonexit";
            this->buttonexit->Size = System::Drawing::Size(131, 30);
            this->buttonexit->TabIndex = 1;
            this->buttonexit->Text = L"Выход из программы";
            this->buttonexit->UseVisualStyleBackColor = false;
            this->buttonexit->Click += gcnew System::EventHandler(this, &MyForm1::buttonexit2_Click);
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->button1->Location = System::Drawing::Point(1133, 0);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(122, 30);
            this->button1->TabIndex = 14;
            this->button1->Text = L"Обновить список";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click_1);
            // 
            // label2
            // 
            this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(873, 69);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(254, 97);
            this->label2->TabIndex = 34;
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label1
            // 
            this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label1->Location = System::Drawing::Point(12, 69);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(855, 97);
            this->label1->TabIndex = 32;
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox2
            // 
            this->checkBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox2.BackgroundImage")));
            this->checkBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox2->Location = System::Drawing::Point(1133, 243);
            this->checkBox2->Name = L"checkBox2";
            this->checkBox2->Size = System::Drawing::Size(159, 97);
            this->checkBox2->TabIndex = 39;
            this->checkBox2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox2->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox2->UseVisualStyleBackColor = true;
            this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox2_CheckedChanged);
            // 
            // label3
            // 
            this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label3->Location = System::Drawing::Point(12, 243);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(855, 97);
            this->label3->TabIndex = 38;
            this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label4
            // 
            this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(873, 243);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(254, 97);
            this->label4->TabIndex = 36;
            this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox3
            // 
            this->checkBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox3.BackgroundImage")));
            this->checkBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox3->Location = System::Drawing::Point(1133, 417);
            this->checkBox3->Name = L"checkBox3";
            this->checkBox3->Size = System::Drawing::Size(159, 97);
            this->checkBox3->TabIndex = 43;
            this->checkBox3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox3->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox3->UseVisualStyleBackColor = true;
            this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox3_CheckedChanged);
            // 
            // label5
            // 
            this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label5->Location = System::Drawing::Point(12, 417);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(855, 97);
            this->label5->TabIndex = 42;
            this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label6
            // 
            this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(873, 417);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(254, 97);
            this->label6->TabIndex = 40;
            this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox4
            // 
            this->checkBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox4.BackgroundImage")));
            this->checkBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox4->Location = System::Drawing::Point(1133, 591);
            this->checkBox4->Name = L"checkBox4";
            this->checkBox4->Size = System::Drawing::Size(159, 97);
            this->checkBox4->TabIndex = 47;
            this->checkBox4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox4->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox4->UseVisualStyleBackColor = true;
            this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox4_CheckedChanged);
            // 
            // label7
            // 
            this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label7->Location = System::Drawing::Point(12, 591);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(855, 97);
            this->label7->TabIndex = 46;
            this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label8
            // 
            this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(873, 591);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(254, 97);
            this->label8->TabIndex = 44;
            this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox5
            // 
            this->checkBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox5.BackgroundImage")));
            this->checkBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox5->Location = System::Drawing::Point(1133, 765);
            this->checkBox5->Name = L"checkBox5";
            this->checkBox5->Size = System::Drawing::Size(159, 97);
            this->checkBox5->TabIndex = 51;
            this->checkBox5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox5->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox5->UseVisualStyleBackColor = true;
            this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox5_CheckedChanged);
            // 
            // label9
            // 
            this->label9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label9->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label9->Location = System::Drawing::Point(12, 765);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(855, 97);
            this->label9->TabIndex = 50;
            this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label10
            // 
            this->label10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label10->Location = System::Drawing::Point(873, 765);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(254, 97);
            this->label10->TabIndex = 48;
            this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox6
            // 
            this->checkBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox6.BackgroundImage")));
            this->checkBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox6->Location = System::Drawing::Point(1133, 939);
            this->checkBox6->Name = L"checkBox6";
            this->checkBox6->Size = System::Drawing::Size(159, 97);
            this->checkBox6->TabIndex = 55;
            this->checkBox6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox6->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox6->UseVisualStyleBackColor = true;
            this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox6_CheckedChanged);
            // 
            // label11
            // 
            this->label11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label11->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label11->Location = System::Drawing::Point(12, 939);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(855, 97);
            this->label11->TabIndex = 54;
            this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label12
            // 
            this->label12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label12->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label12->Location = System::Drawing::Point(873, 939);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(254, 97);
            this->label12->TabIndex = 52;
            this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox7
            // 
            this->checkBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox7.BackgroundImage")));
            this->checkBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox7->Location = System::Drawing::Point(1133, 1113);
            this->checkBox7->Name = L"checkBox7";
            this->checkBox7->Size = System::Drawing::Size(159, 97);
            this->checkBox7->TabIndex = 59;
            this->checkBox7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox7->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox7->UseVisualStyleBackColor = true;
            this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox7_CheckedChanged);
            // 
            // label13
            // 
            this->label13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label13->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label13->Location = System::Drawing::Point(12, 1113);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(855, 97);
            this->label13->TabIndex = 58;
            this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label14
            // 
            this->label14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label14->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label14->Location = System::Drawing::Point(873, 1113);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(254, 97);
            this->label14->TabIndex = 56;
            this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox8
            // 
            this->checkBox8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox8.BackgroundImage")));
            this->checkBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox8->Location = System::Drawing::Point(1133, 1287);
            this->checkBox8->Name = L"checkBox8";
            this->checkBox8->Size = System::Drawing::Size(159, 97);
            this->checkBox8->TabIndex = 63;
            this->checkBox8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox8->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox8->UseVisualStyleBackColor = true;
            this->checkBox8->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox8_CheckedChanged);
            // 
            // label15
            // 
            this->label15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label15->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label15->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label15->Location = System::Drawing::Point(12, 1287);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(855, 97);
            this->label15->TabIndex = 62;
            this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label16
            // 
            this->label16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label16->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label16->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label16->Location = System::Drawing::Point(873, 1287);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(254, 97);
            this->label16->TabIndex = 60;
            this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox9
            // 
            this->checkBox9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox9.BackgroundImage")));
            this->checkBox9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox9->Location = System::Drawing::Point(1133, 1461);
            this->checkBox9->Name = L"checkBox9";
            this->checkBox9->Size = System::Drawing::Size(159, 97);
            this->checkBox9->TabIndex = 67;
            this->checkBox9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox9->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox9->UseVisualStyleBackColor = true;
            this->checkBox9->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox9_CheckedChanged);
            // 
            // label17
            // 
            this->label17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label17->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label17->Location = System::Drawing::Point(12, 1461);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(855, 97);
            this->label17->TabIndex = 66;
            this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label18
            // 
            this->label18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label18->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label18->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label18->Location = System::Drawing::Point(873, 1461);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(254, 97);
            this->label18->TabIndex = 64;
            this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox10
            // 
            this->checkBox10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox10.BackgroundImage")));
            this->checkBox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox10->Location = System::Drawing::Point(1133, 1635);
            this->checkBox10->Name = L"checkBox10";
            this->checkBox10->Size = System::Drawing::Size(159, 97);
            this->checkBox10->TabIndex = 71;
            this->checkBox10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox10->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox10->UseVisualStyleBackColor = true;
            this->checkBox10->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox10_CheckedChanged);
            // 
            // label19
            // 
            this->label19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label19->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label19->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label19->Location = System::Drawing::Point(12, 1635);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(855, 97);
            this->label19->TabIndex = 70;
            this->label19->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label20
            // 
            this->label20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label20->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label20->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label20->Location = System::Drawing::Point(873, 1635);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(254, 97);
            this->label20->TabIndex = 68;
            this->label20->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox11
            // 
            this->checkBox11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox11.BackgroundImage")));
            this->checkBox11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox11->Location = System::Drawing::Point(1133, 1809);
            this->checkBox11->Name = L"checkBox11";
            this->checkBox11->Size = System::Drawing::Size(159, 97);
            this->checkBox11->TabIndex = 75;
            this->checkBox11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox11->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox11->UseVisualStyleBackColor = true;
            this->checkBox11->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox11_CheckedChanged);
            // 
            // label21
            // 
            this->label21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label21->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label21->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label21->Location = System::Drawing::Point(12, 1809);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(855, 97);
            this->label21->TabIndex = 74;
            this->label21->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label22
            // 
            this->label22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label22->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label22->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label22->Location = System::Drawing::Point(873, 1809);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(254, 97);
            this->label22->TabIndex = 72;
            this->label22->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox12
            // 
            this->checkBox12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox12.BackgroundImage")));
            this->checkBox12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox12->Location = System::Drawing::Point(1133, 1983);
            this->checkBox12->Name = L"checkBox12";
            this->checkBox12->Size = System::Drawing::Size(159, 97);
            this->checkBox12->TabIndex = 79;
            this->checkBox12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox12->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox12->UseVisualStyleBackColor = true;
            this->checkBox12->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox12_CheckedChanged);
            // 
            // label23
            // 
            this->label23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label23->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label23->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label23->Location = System::Drawing::Point(12, 1983);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(855, 97);
            this->label23->TabIndex = 78;
            this->label23->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label24
            // 
            this->label24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label24->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label24->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label24->Location = System::Drawing::Point(873, 1983);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(254, 97);
            this->label24->TabIndex = 76;
            this->label24->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox13
            // 
            this->checkBox13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox13.BackgroundImage")));
            this->checkBox13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox13->Location = System::Drawing::Point(1133, 2157);
            this->checkBox13->Name = L"checkBox13";
            this->checkBox13->Size = System::Drawing::Size(159, 97);
            this->checkBox13->TabIndex = 83;
            this->checkBox13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox13->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox13->UseVisualStyleBackColor = true;
            this->checkBox13->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox13_CheckedChanged);
            // 
            // label25
            // 
            this->label25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label25->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label25->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label25->Location = System::Drawing::Point(12, 2157);
            this->label25->Name = L"label25";
            this->label25->Size = System::Drawing::Size(855, 97);
            this->label25->TabIndex = 82;
            this->label25->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label26
            // 
            this->label26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label26->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label26->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label26->Location = System::Drawing::Point(873, 2157);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(254, 97);
            this->label26->TabIndex = 80;
            this->label26->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox14
            // 
            this->checkBox14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox14.BackgroundImage")));
            this->checkBox14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox14->Location = System::Drawing::Point(1133, 2331);
            this->checkBox14->Name = L"checkBox14";
            this->checkBox14->Size = System::Drawing::Size(159, 97);
            this->checkBox14->TabIndex = 87;
            this->checkBox14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox14->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox14->UseVisualStyleBackColor = true;
            this->checkBox14->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox14_CheckedChanged);
            // 
            // label27
            // 
            this->label27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label27->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label27->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label27->Location = System::Drawing::Point(12, 2331);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(855, 97);
            this->label27->TabIndex = 86;
            this->label27->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label28
            // 
            this->label28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label28->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label28->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label28->Location = System::Drawing::Point(873, 2331);
            this->label28->Name = L"label28";
            this->label28->Size = System::Drawing::Size(254, 97);
            this->label28->TabIndex = 84;
            this->label28->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox15
            // 
            this->checkBox15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox15.BackgroundImage")));
            this->checkBox15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox15->Location = System::Drawing::Point(1133, 2505);
            this->checkBox15->Name = L"checkBox15";
            this->checkBox15->Size = System::Drawing::Size(159, 97);
            this->checkBox15->TabIndex = 91;
            this->checkBox15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox15->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox15->UseVisualStyleBackColor = true;
            this->checkBox15->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox15_CheckedChanged);
            // 
            // label29
            // 
            this->label29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label29->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label29->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label29->Location = System::Drawing::Point(12, 2505);
            this->label29->Name = L"label29";
            this->label29->Size = System::Drawing::Size(855, 97);
            this->label29->TabIndex = 90;
            this->label29->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label30
            // 
            this->label30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label30->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label30->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label30->Location = System::Drawing::Point(873, 2505);
            this->label30->Name = L"label30";
            this->label30->Size = System::Drawing::Size(254, 97);
            this->label30->TabIndex = 88;
            this->label30->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox16
            // 
            this->checkBox16->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox16.BackgroundImage")));
            this->checkBox16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox16->Location = System::Drawing::Point(1133, 2679);
            this->checkBox16->Name = L"checkBox16";
            this->checkBox16->Size = System::Drawing::Size(159, 97);
            this->checkBox16->TabIndex = 95;
            this->checkBox16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox16->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox16->UseVisualStyleBackColor = true;
            this->checkBox16->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox16_CheckedChanged);
            // 
            // label31
            // 
            this->label31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label31->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label31->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label31->Location = System::Drawing::Point(12, 2679);
            this->label31->Name = L"label31";
            this->label31->Size = System::Drawing::Size(855, 97);
            this->label31->TabIndex = 94;
            this->label31->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label32
            // 
            this->label32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label32->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label32->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label32->Location = System::Drawing::Point(873, 2679);
            this->label32->Name = L"label32";
            this->label32->Size = System::Drawing::Size(254, 97);
            this->label32->TabIndex = 92;
            this->label32->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox17
            // 
            this->checkBox17->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox17.BackgroundImage")));
            this->checkBox17->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox17->Location = System::Drawing::Point(1133, 2854);
            this->checkBox17->Name = L"checkBox17";
            this->checkBox17->Size = System::Drawing::Size(159, 97);
            this->checkBox17->TabIndex = 99;
            this->checkBox17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox17->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox17->UseVisualStyleBackColor = true;
            this->checkBox17->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox17_CheckedChanged);
            // 
            // label33
            // 
            this->label33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label33->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label33->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label33->Location = System::Drawing::Point(12, 2854);
            this->label33->Name = L"label33";
            this->label33->Size = System::Drawing::Size(855, 97);
            this->label33->TabIndex = 98;
            this->label33->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label34
            // 
            this->label34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label34->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label34->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label34->Location = System::Drawing::Point(873, 2854);
            this->label34->Name = L"label34";
            this->label34->Size = System::Drawing::Size(254, 97);
            this->label34->TabIndex = 96;
            this->label34->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox18
            // 
            this->checkBox18->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox18.BackgroundImage")));
            this->checkBox18->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox18->Location = System::Drawing::Point(1133, 3028);
            this->checkBox18->Name = L"checkBox18";
            this->checkBox18->Size = System::Drawing::Size(159, 97);
            this->checkBox18->TabIndex = 103;
            this->checkBox18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox18->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox18->UseVisualStyleBackColor = true;
            this->checkBox18->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox18_CheckedChanged);
            // 
            // label35
            // 
            this->label35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label35->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label35->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label35->Location = System::Drawing::Point(12, 3028);
            this->label35->Name = L"label35";
            this->label35->Size = System::Drawing::Size(855, 97);
            this->label35->TabIndex = 102;
            this->label35->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label36
            // 
            this->label36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label36->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label36->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label36->Location = System::Drawing::Point(873, 3028);
            this->label36->Name = L"label36";
            this->label36->Size = System::Drawing::Size(254, 97);
            this->label36->TabIndex = 100;
            this->label36->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox19
            // 
            this->checkBox19->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox19.BackgroundImage")));
            this->checkBox19->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox19->Location = System::Drawing::Point(1133, 3202);
            this->checkBox19->Name = L"checkBox19";
            this->checkBox19->Size = System::Drawing::Size(159, 97);
            this->checkBox19->TabIndex = 107;
            this->checkBox19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox19->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox19->UseVisualStyleBackColor = true;
            this->checkBox19->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox19_CheckedChanged);
            // 
            // label37
            // 
            this->label37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label37->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label37->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label37->Location = System::Drawing::Point(12, 3202);
            this->label37->Name = L"label37";
            this->label37->Size = System::Drawing::Size(855, 97);
            this->label37->TabIndex = 106;
            this->label37->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label38
            // 
            this->label38->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label38->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label38->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label38->Location = System::Drawing::Point(873, 3202);
            this->label38->Name = L"label38";
            this->label38->Size = System::Drawing::Size(254, 97);
            this->label38->TabIndex = 104;
            this->label38->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox20
            // 
            this->checkBox20->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox20.BackgroundImage")));
            this->checkBox20->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox20->Location = System::Drawing::Point(1133, 3376);
            this->checkBox20->Name = L"checkBox20";
            this->checkBox20->Size = System::Drawing::Size(159, 97);
            this->checkBox20->TabIndex = 111;
            this->checkBox20->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox20->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox20->UseVisualStyleBackColor = true;
            this->checkBox20->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox20_CheckedChanged);
            // 
            // label39
            // 
            this->label39->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label39->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label39->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label39->Location = System::Drawing::Point(12, 3376);
            this->label39->Name = L"label39";
            this->label39->Size = System::Drawing::Size(855, 97);
            this->label39->TabIndex = 110;
            this->label39->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label40
            // 
            this->label40->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label40->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label40->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label40->Location = System::Drawing::Point(873, 3376);
            this->label40->Name = L"label40";
            this->label40->Size = System::Drawing::Size(254, 97);
            this->label40->TabIndex = 108;
            this->label40->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox21
            // 
            this->checkBox21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox21.BackgroundImage")));
            this->checkBox21->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox21->Location = System::Drawing::Point(1133, 3550);
            this->checkBox21->Name = L"checkBox21";
            this->checkBox21->Size = System::Drawing::Size(159, 97);
            this->checkBox21->TabIndex = 115;
            this->checkBox21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox21->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox21->UseVisualStyleBackColor = true;
            this->checkBox21->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox21_CheckedChanged);
            // 
            // label41
            // 
            this->label41->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label41->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label41->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label41->Location = System::Drawing::Point(12, 3550);
            this->label41->Name = L"label41";
            this->label41->Size = System::Drawing::Size(855, 97);
            this->label41->TabIndex = 114;
            this->label41->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label42
            // 
            this->label42->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label42->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label42->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label42->Location = System::Drawing::Point(873, 3550);
            this->label42->Name = L"label42";
            this->label42->Size = System::Drawing::Size(254, 97);
            this->label42->TabIndex = 112;
            this->label42->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox22
            // 
            this->checkBox22->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox22.BackgroundImage")));
            this->checkBox22->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox22->Location = System::Drawing::Point(1133, 3724);
            this->checkBox22->Name = L"checkBox22";
            this->checkBox22->Size = System::Drawing::Size(159, 97);
            this->checkBox22->TabIndex = 119;
            this->checkBox22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox22->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox22->UseVisualStyleBackColor = true;
            this->checkBox22->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox22_CheckedChanged);
            // 
            // label43
            // 
            this->label43->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label43->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label43->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label43->Location = System::Drawing::Point(12, 3724);
            this->label43->Name = L"label43";
            this->label43->Size = System::Drawing::Size(855, 97);
            this->label43->TabIndex = 118;
            this->label43->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label44
            // 
            this->label44->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label44->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label44->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label44->Location = System::Drawing::Point(873, 3724);
            this->label44->Name = L"label44";
            this->label44->Size = System::Drawing::Size(254, 97);
            this->label44->TabIndex = 116;
            this->label44->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox23
            // 
            this->checkBox23->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox23.BackgroundImage")));
            this->checkBox23->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox23->Location = System::Drawing::Point(1133, 3898);
            this->checkBox23->Name = L"checkBox23";
            this->checkBox23->Size = System::Drawing::Size(159, 97);
            this->checkBox23->TabIndex = 123;
            this->checkBox23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox23->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox23->UseVisualStyleBackColor = true;
            this->checkBox23->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox23_CheckedChanged);
            // 
            // label45
            // 
            this->label45->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label45->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label45->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label45->Location = System::Drawing::Point(12, 3898);
            this->label45->Name = L"label45";
            this->label45->Size = System::Drawing::Size(855, 97);
            this->label45->TabIndex = 122;
            this->label45->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label46
            // 
            this->label46->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label46->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label46->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label46->Location = System::Drawing::Point(873, 3898);
            this->label46->Name = L"label46";
            this->label46->Size = System::Drawing::Size(254, 97);
            this->label46->TabIndex = 120;
            this->label46->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox24
            // 
            this->checkBox24->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox24.BackgroundImage")));
            this->checkBox24->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox24->Location = System::Drawing::Point(1133, 4072);
            this->checkBox24->Name = L"checkBox24";
            this->checkBox24->Size = System::Drawing::Size(159, 97);
            this->checkBox24->TabIndex = 127;
            this->checkBox24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox24->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox24->UseVisualStyleBackColor = true;
            this->checkBox24->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox24_CheckedChanged);
            // 
            // label47
            // 
            this->label47->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label47->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label47->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label47->Location = System::Drawing::Point(12, 4072);
            this->label47->Name = L"label47";
            this->label47->Size = System::Drawing::Size(855, 97);
            this->label47->TabIndex = 126;
            this->label47->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label48
            // 
            this->label48->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label48->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label48->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label48->Location = System::Drawing::Point(873, 4072);
            this->label48->Name = L"label48";
            this->label48->Size = System::Drawing::Size(254, 97);
            this->label48->TabIndex = 124;
            this->label48->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox25
            // 
            this->checkBox25->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox25.BackgroundImage")));
            this->checkBox25->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox25->Location = System::Drawing::Point(1133, 4246);
            this->checkBox25->Name = L"checkBox25";
            this->checkBox25->Size = System::Drawing::Size(159, 97);
            this->checkBox25->TabIndex = 131;
            this->checkBox25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox25->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox25->UseVisualStyleBackColor = true;
            this->checkBox25->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox25_CheckedChanged);
            // 
            // label49
            // 
            this->label49->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label49->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label49->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label49->Location = System::Drawing::Point(12, 4246);
            this->label49->Name = L"label49";
            this->label49->Size = System::Drawing::Size(855, 97);
            this->label49->TabIndex = 130;
            this->label49->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label50
            // 
            this->label50->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label50->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label50->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label50->Location = System::Drawing::Point(873, 4246);
            this->label50->Name = L"label50";
            this->label50->Size = System::Drawing::Size(254, 97);
            this->label50->TabIndex = 128;
            this->label50->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox26
            // 
            this->checkBox26->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox26.BackgroundImage")));
            this->checkBox26->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox26->Location = System::Drawing::Point(1133, 4420);
            this->checkBox26->Name = L"checkBox26";
            this->checkBox26->Size = System::Drawing::Size(159, 97);
            this->checkBox26->TabIndex = 135;
            this->checkBox26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox26->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox26->UseVisualStyleBackColor = true;
            this->checkBox26->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox26_CheckedChanged);
            // 
            // label51
            // 
            this->label51->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label51->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label51->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label51->Location = System::Drawing::Point(12, 4420);
            this->label51->Name = L"label51";
            this->label51->Size = System::Drawing::Size(855, 97);
            this->label51->TabIndex = 134;
            this->label51->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label52
            // 
            this->label52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label52->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label52->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label52->Location = System::Drawing::Point(873, 4420);
            this->label52->Name = L"label52";
            this->label52->Size = System::Drawing::Size(254, 97);
            this->label52->TabIndex = 132;
            this->label52->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox27
            // 
            this->checkBox27->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox27.BackgroundImage")));
            this->checkBox27->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox27->Location = System::Drawing::Point(1133, 4594);
            this->checkBox27->Name = L"checkBox27";
            this->checkBox27->Size = System::Drawing::Size(159, 97);
            this->checkBox27->TabIndex = 139;
            this->checkBox27->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox27->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox27->UseVisualStyleBackColor = true;
            this->checkBox27->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox27_CheckedChanged);
            // 
            // label53
            // 
            this->label53->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label53->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label53->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label53->Location = System::Drawing::Point(12, 4594);
            this->label53->Name = L"label53";
            this->label53->Size = System::Drawing::Size(855, 97);
            this->label53->TabIndex = 138;
            this->label53->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label54
            // 
            this->label54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label54->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label54->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label54->Location = System::Drawing::Point(873, 4594);
            this->label54->Name = L"label54";
            this->label54->Size = System::Drawing::Size(254, 97);
            this->label54->TabIndex = 136;
            this->label54->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox28
            // 
            this->checkBox28->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox28.BackgroundImage")));
            this->checkBox28->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox28->Location = System::Drawing::Point(1133, 4768);
            this->checkBox28->Name = L"checkBox28";
            this->checkBox28->Size = System::Drawing::Size(159, 97);
            this->checkBox28->TabIndex = 143;
            this->checkBox28->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox28->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox28->UseVisualStyleBackColor = true;
            this->checkBox28->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox28_CheckedChanged);
            // 
            // label55
            // 
            this->label55->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label55->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label55->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label55->Location = System::Drawing::Point(12, 4768);
            this->label55->Name = L"label55";
            this->label55->Size = System::Drawing::Size(855, 97);
            this->label55->TabIndex = 142;
            this->label55->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label56
            // 
            this->label56->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label56->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label56->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label56->Location = System::Drawing::Point(873, 4768);
            this->label56->Name = L"label56";
            this->label56->Size = System::Drawing::Size(254, 97);
            this->label56->TabIndex = 140;
            this->label56->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox29
            // 
            this->checkBox29->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox29.BackgroundImage")));
            this->checkBox29->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox29->Location = System::Drawing::Point(1133, 4942);
            this->checkBox29->Name = L"checkBox29";
            this->checkBox29->Size = System::Drawing::Size(159, 97);
            this->checkBox29->TabIndex = 147;
            this->checkBox29->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox29->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox29->UseVisualStyleBackColor = true;
            this->checkBox29->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox29_CheckedChanged);
            // 
            // label57
            // 
            this->label57->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label57->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label57->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label57->Location = System::Drawing::Point(12, 4942);
            this->label57->Name = L"label57";
            this->label57->Size = System::Drawing::Size(855, 97);
            this->label57->TabIndex = 146;
            this->label57->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label58
            // 
            this->label58->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label58->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label58->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label58->Location = System::Drawing::Point(873, 4942);
            this->label58->Name = L"label58";
            this->label58->Size = System::Drawing::Size(254, 97);
            this->label58->TabIndex = 144;
            this->label58->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox30
            // 
            this->checkBox30->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox30.BackgroundImage")));
            this->checkBox30->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox30->Location = System::Drawing::Point(1133, 5116);
            this->checkBox30->Name = L"checkBox30";
            this->checkBox30->Size = System::Drawing::Size(159, 97);
            this->checkBox30->TabIndex = 151;
            this->checkBox30->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox30->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox30->UseVisualStyleBackColor = true;
            this->checkBox30->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox30_CheckedChanged);
            // 
            // label59
            // 
            this->label59->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label59->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label59->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label59->Location = System::Drawing::Point(12, 5116);
            this->label59->Name = L"label59";
            this->label59->Size = System::Drawing::Size(855, 97);
            this->label59->TabIndex = 150;
            this->label59->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label60
            // 
            this->label60->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label60->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label60->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label60->Location = System::Drawing::Point(873, 5116);
            this->label60->Name = L"label60";
            this->label60->Size = System::Drawing::Size(254, 97);
            this->label60->TabIndex = 148;
            this->label60->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox31
            // 
            this->checkBox31->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox31.BackgroundImage")));
            this->checkBox31->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox31->Location = System::Drawing::Point(1133, 5290);
            this->checkBox31->Name = L"checkBox31";
            this->checkBox31->Size = System::Drawing::Size(159, 97);
            this->checkBox31->TabIndex = 155;
            this->checkBox31->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox31->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox31->UseVisualStyleBackColor = true;
            this->checkBox31->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox31_CheckedChanged);
            // 
            // label61
            // 
            this->label61->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label61->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label61->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label61->Location = System::Drawing::Point(12, 5290);
            this->label61->Name = L"label61";
            this->label61->Size = System::Drawing::Size(855, 97);
            this->label61->TabIndex = 154;
            this->label61->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label62
            // 
            this->label62->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label62->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label62->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label62->Location = System::Drawing::Point(873, 5290);
            this->label62->Name = L"label62";
            this->label62->Size = System::Drawing::Size(254, 97);
            this->label62->TabIndex = 152;
            this->label62->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox32
            // 
            this->checkBox32->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox32.BackgroundImage")));
            this->checkBox32->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox32->Location = System::Drawing::Point(1133, 5464);
            this->checkBox32->Name = L"checkBox32";
            this->checkBox32->Size = System::Drawing::Size(159, 97);
            this->checkBox32->TabIndex = 159;
            this->checkBox32->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox32->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox32->UseVisualStyleBackColor = true;
            this->checkBox32->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox32_CheckedChanged);
            // 
            // label63
            // 
            this->label63->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label63->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label63->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label63->Location = System::Drawing::Point(12, 5464);
            this->label63->Name = L"label63";
            this->label63->Size = System::Drawing::Size(855, 97);
            this->label63->TabIndex = 158;
            this->label63->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label64
            // 
            this->label64->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label64->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label64->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label64->Location = System::Drawing::Point(873, 5464);
            this->label64->Name = L"label64";
            this->label64->Size = System::Drawing::Size(254, 97);
            this->label64->TabIndex = 156;
            this->label64->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox33
            // 
            this->checkBox33->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox33.BackgroundImage")));
            this->checkBox33->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox33->Location = System::Drawing::Point(1133, 5638);
            this->checkBox33->Name = L"checkBox33";
            this->checkBox33->Size = System::Drawing::Size(159, 97);
            this->checkBox33->TabIndex = 163;
            this->checkBox33->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox33->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox33->UseVisualStyleBackColor = true;
            this->checkBox33->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox33_CheckedChanged);
            // 
            // label65
            // 
            this->label65->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label65->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label65->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label65->Location = System::Drawing::Point(12, 5638);
            this->label65->Name = L"label65";
            this->label65->Size = System::Drawing::Size(855, 97);
            this->label65->TabIndex = 162;
            this->label65->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label66
            // 
            this->label66->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label66->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label66->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label66->Location = System::Drawing::Point(873, 5638);
            this->label66->Name = L"label66";
            this->label66->Size = System::Drawing::Size(254, 97);
            this->label66->TabIndex = 160;
            this->label66->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox34
            // 
            this->checkBox34->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox34.BackgroundImage")));
            this->checkBox34->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox34->Location = System::Drawing::Point(1133, 5812);
            this->checkBox34->Name = L"checkBox34";
            this->checkBox34->Size = System::Drawing::Size(159, 97);
            this->checkBox34->TabIndex = 167;
            this->checkBox34->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox34->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox34->UseVisualStyleBackColor = true;
            this->checkBox34->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox34_CheckedChanged);
            // 
            // label67
            // 
            this->label67->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label67->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label67->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label67->Location = System::Drawing::Point(12, 5812);
            this->label67->Name = L"label67";
            this->label67->Size = System::Drawing::Size(855, 97);
            this->label67->TabIndex = 166;
            this->label67->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label68
            // 
            this->label68->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label68->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label68->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label68->Location = System::Drawing::Point(873, 5812);
            this->label68->Name = L"label68";
            this->label68->Size = System::Drawing::Size(254, 97);
            this->label68->TabIndex = 164;
            this->label68->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox35
            // 
            this->checkBox35->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox35.BackgroundImage")));
            this->checkBox35->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox35->Location = System::Drawing::Point(1133, 5986);
            this->checkBox35->Name = L"checkBox35";
            this->checkBox35->Size = System::Drawing::Size(159, 97);
            this->checkBox35->TabIndex = 171;
            this->checkBox35->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox35->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox35->UseVisualStyleBackColor = true;
            this->checkBox35->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox35_CheckedChanged);
            // 
            // label69
            // 
            this->label69->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label69->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label69->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label69->Location = System::Drawing::Point(12, 5986);
            this->label69->Name = L"label69";
            this->label69->Size = System::Drawing::Size(855, 97);
            this->label69->TabIndex = 170;
            this->label69->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label70
            // 
            this->label70->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label70->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label70->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label70->Location = System::Drawing::Point(873, 5986);
            this->label70->Name = L"label70";
            this->label70->Size = System::Drawing::Size(254, 97);
            this->label70->TabIndex = 168;
            this->label70->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox36
            // 
            this->checkBox36->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox36.BackgroundImage")));
            this->checkBox36->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox36->Location = System::Drawing::Point(1133, 6160);
            this->checkBox36->Name = L"checkBox36";
            this->checkBox36->Size = System::Drawing::Size(159, 97);
            this->checkBox36->TabIndex = 175;
            this->checkBox36->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox36->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox36->UseVisualStyleBackColor = true;
            this->checkBox36->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox36_CheckedChanged);
            // 
            // label71
            // 
            this->label71->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label71->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label71->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label71->Location = System::Drawing::Point(12, 6160);
            this->label71->Name = L"label71";
            this->label71->Size = System::Drawing::Size(855, 97);
            this->label71->TabIndex = 174;
            this->label71->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label72
            // 
            this->label72->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label72->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label72->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label72->Location = System::Drawing::Point(873, 6160);
            this->label72->Name = L"label72";
            this->label72->Size = System::Drawing::Size(254, 97);
            this->label72->TabIndex = 172;
            this->label72->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox37
            // 
            this->checkBox37->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox37.BackgroundImage")));
            this->checkBox37->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox37->Location = System::Drawing::Point(1133, 6334);
            this->checkBox37->Name = L"checkBox37";
            this->checkBox37->Size = System::Drawing::Size(159, 97);
            this->checkBox37->TabIndex = 179;
            this->checkBox37->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox37->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox37->UseVisualStyleBackColor = true;
            this->checkBox37->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox37_CheckedChanged);
            // 
            // label73
            // 
            this->label73->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label73->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label73->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label73->Location = System::Drawing::Point(12, 6334);
            this->label73->Name = L"label73";
            this->label73->Size = System::Drawing::Size(855, 97);
            this->label73->TabIndex = 178;
            this->label73->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label74
            // 
            this->label74->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label74->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label74->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label74->Location = System::Drawing::Point(873, 6334);
            this->label74->Name = L"label74";
            this->label74->Size = System::Drawing::Size(254, 97);
            this->label74->TabIndex = 176;
            this->label74->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox38
            // 
            this->checkBox38->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox38.BackgroundImage")));
            this->checkBox38->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox38->Location = System::Drawing::Point(1133, 6508);
            this->checkBox38->Name = L"checkBox38";
            this->checkBox38->Size = System::Drawing::Size(159, 97);
            this->checkBox38->TabIndex = 183;
            this->checkBox38->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox38->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox38->UseVisualStyleBackColor = true;
            this->checkBox38->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox38_CheckedChanged);
            // 
            // label75
            // 
            this->label75->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label75->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label75->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label75->Location = System::Drawing::Point(12, 6508);
            this->label75->Name = L"label75";
            this->label75->Size = System::Drawing::Size(855, 97);
            this->label75->TabIndex = 182;
            this->label75->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label76
            // 
            this->label76->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label76->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label76->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label76->Location = System::Drawing::Point(873, 6508);
            this->label76->Name = L"label76";
            this->label76->Size = System::Drawing::Size(254, 97);
            this->label76->TabIndex = 180;
            this->label76->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox39
            // 
            this->checkBox39->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox39.BackgroundImage")));
            this->checkBox39->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox39->Location = System::Drawing::Point(1133, 6682);
            this->checkBox39->Name = L"checkBox39";
            this->checkBox39->Size = System::Drawing::Size(159, 97);
            this->checkBox39->TabIndex = 187;
            this->checkBox39->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox39->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox39->UseVisualStyleBackColor = true;
            this->checkBox39->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox39_CheckedChanged);
            // 
            // label77
            // 
            this->label77->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label77->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label77->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label77->Location = System::Drawing::Point(12, 6682);
            this->label77->Name = L"label77";
            this->label77->Size = System::Drawing::Size(855, 97);
            this->label77->TabIndex = 186;
            this->label77->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label78
            // 
            this->label78->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label78->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label78->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label78->Location = System::Drawing::Point(873, 6682);
            this->label78->Name = L"label78";
            this->label78->Size = System::Drawing::Size(254, 97);
            this->label78->TabIndex = 184;
            this->label78->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox40
            // 
            this->checkBox40->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox40.BackgroundImage")));
            this->checkBox40->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox40->Location = System::Drawing::Point(1133, 6856);
            this->checkBox40->Name = L"checkBox40";
            this->checkBox40->Size = System::Drawing::Size(159, 97);
            this->checkBox40->TabIndex = 191;
            this->checkBox40->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox40->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox40->UseVisualStyleBackColor = true;
            this->checkBox40->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox40_CheckedChanged);
            // 
            // label79
            // 
            this->label79->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label79->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label79->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label79->Location = System::Drawing::Point(12, 6856);
            this->label79->Name = L"label79";
            this->label79->Size = System::Drawing::Size(855, 97);
            this->label79->TabIndex = 190;
            this->label79->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label80
            // 
            this->label80->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label80->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label80->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label80->Location = System::Drawing::Point(873, 6856);
            this->label80->Name = L"label80";
            this->label80->Size = System::Drawing::Size(254, 97);
            this->label80->TabIndex = 188;
            this->label80->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox41
            // 
            this->checkBox41->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox41.BackgroundImage")));
            this->checkBox41->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox41->Location = System::Drawing::Point(1133, 7030);
            this->checkBox41->Name = L"checkBox41";
            this->checkBox41->Size = System::Drawing::Size(159, 97);
            this->checkBox41->TabIndex = 195;
            this->checkBox41->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox41->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox41->UseVisualStyleBackColor = true;
            this->checkBox41->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox41_CheckedChanged);
            // 
            // label81
            // 
            this->label81->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label81->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label81->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label81->Location = System::Drawing::Point(12, 7030);
            this->label81->Name = L"label81";
            this->label81->Size = System::Drawing::Size(855, 97);
            this->label81->TabIndex = 194;
            this->label81->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label82
            // 
            this->label82->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label82->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label82->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label82->Location = System::Drawing::Point(873, 7030);
            this->label82->Name = L"label82";
            this->label82->Size = System::Drawing::Size(254, 97);
            this->label82->TabIndex = 192;
            this->label82->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox42
            // 
            this->checkBox42->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox42.BackgroundImage")));
            this->checkBox42->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox42->Location = System::Drawing::Point(1133, 7204);
            this->checkBox42->Name = L"checkBox42";
            this->checkBox42->Size = System::Drawing::Size(159, 97);
            this->checkBox42->TabIndex = 199;
            this->checkBox42->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox42->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox42->UseVisualStyleBackColor = true;
            this->checkBox42->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox42_CheckedChanged);
            // 
            // label83
            // 
            this->label83->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label83->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label83->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label83->Location = System::Drawing::Point(12, 7204);
            this->label83->Name = L"label83";
            this->label83->Size = System::Drawing::Size(855, 97);
            this->label83->TabIndex = 198;
            this->label83->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label84
            // 
            this->label84->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label84->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label84->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label84->Location = System::Drawing::Point(873, 7204);
            this->label84->Name = L"label84";
            this->label84->Size = System::Drawing::Size(254, 97);
            this->label84->TabIndex = 196;
            this->label84->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox43
            // 
            this->checkBox43->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox43.BackgroundImage")));
            this->checkBox43->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox43->Location = System::Drawing::Point(1133, 7378);
            this->checkBox43->Name = L"checkBox43";
            this->checkBox43->Size = System::Drawing::Size(159, 97);
            this->checkBox43->TabIndex = 203;
            this->checkBox43->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox43->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox43->UseVisualStyleBackColor = true;
            this->checkBox43->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox43_CheckedChanged);
            // 
            // label85
            // 
            this->label85->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label85->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label85->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label85->Location = System::Drawing::Point(12, 7378);
            this->label85->Name = L"label85";
            this->label85->Size = System::Drawing::Size(855, 97);
            this->label85->TabIndex = 202;
            this->label85->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label86
            // 
            this->label86->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label86->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label86->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label86->Location = System::Drawing::Point(873, 7378);
            this->label86->Name = L"label86";
            this->label86->Size = System::Drawing::Size(254, 97);
            this->label86->TabIndex = 200;
            this->label86->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox44
            // 
            this->checkBox44->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox44.BackgroundImage")));
            this->checkBox44->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox44->Location = System::Drawing::Point(1133, 7552);
            this->checkBox44->Name = L"checkBox44";
            this->checkBox44->Size = System::Drawing::Size(159, 97);
            this->checkBox44->TabIndex = 207;
            this->checkBox44->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox44->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox44->UseVisualStyleBackColor = true;
            this->checkBox44->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox44_CheckedChanged);
            // 
            // label87
            // 
            this->label87->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label87->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label87->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label87->Location = System::Drawing::Point(12, 7552);
            this->label87->Name = L"label87";
            this->label87->Size = System::Drawing::Size(855, 97);
            this->label87->TabIndex = 206;
            this->label87->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label88
            // 
            this->label88->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label88->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label88->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label88->Location = System::Drawing::Point(873, 7552);
            this->label88->Name = L"label88";
            this->label88->Size = System::Drawing::Size(254, 97);
            this->label88->TabIndex = 204;
            this->label88->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox45
            // 
            this->checkBox45->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox45.BackgroundImage")));
            this->checkBox45->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox45->Location = System::Drawing::Point(1133, 7726);
            this->checkBox45->Name = L"checkBox45";
            this->checkBox45->Size = System::Drawing::Size(159, 97);
            this->checkBox45->TabIndex = 211;
            this->checkBox45->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox45->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox45->UseVisualStyleBackColor = true;
            this->checkBox45->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox45_CheckedChanged);
            // 
            // label89
            // 
            this->label89->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label89->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label89->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label89->Location = System::Drawing::Point(12, 7726);
            this->label89->Name = L"label89";
            this->label89->Size = System::Drawing::Size(855, 97);
            this->label89->TabIndex = 210;
            this->label89->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label90
            // 
            this->label90->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label90->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label90->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label90->Location = System::Drawing::Point(873, 7726);
            this->label90->Name = L"label90";
            this->label90->Size = System::Drawing::Size(254, 97);
            this->label90->TabIndex = 208;
            this->label90->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox46
            // 
            this->checkBox46->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox46.BackgroundImage")));
            this->checkBox46->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox46->Location = System::Drawing::Point(1133, 7900);
            this->checkBox46->Name = L"checkBox46";
            this->checkBox46->Size = System::Drawing::Size(159, 97);
            this->checkBox46->TabIndex = 215;
            this->checkBox46->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox46->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox46->UseVisualStyleBackColor = true;
            this->checkBox46->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox46_CheckedChanged);
            // 
            // label91
            // 
            this->label91->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label91->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label91->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label91->Location = System::Drawing::Point(12, 7900);
            this->label91->Name = L"label91";
            this->label91->Size = System::Drawing::Size(855, 97);
            this->label91->TabIndex = 214;
            this->label91->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label92
            // 
            this->label92->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label92->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label92->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label92->Location = System::Drawing::Point(873, 7900);
            this->label92->Name = L"label92";
            this->label92->Size = System::Drawing::Size(254, 97);
            this->label92->TabIndex = 212;
            this->label92->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox47
            // 
            this->checkBox47->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox47.BackgroundImage")));
            this->checkBox47->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox47->Location = System::Drawing::Point(1133, 8074);
            this->checkBox47->Name = L"checkBox47";
            this->checkBox47->Size = System::Drawing::Size(159, 97);
            this->checkBox47->TabIndex = 219;
            this->checkBox47->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox47->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox47->UseVisualStyleBackColor = true;
            this->checkBox47->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox47_CheckedChanged);
            // 
            // label93
            // 
            this->label93->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label93->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label93->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label93->Location = System::Drawing::Point(12, 8074);
            this->label93->Name = L"label93";
            this->label93->Size = System::Drawing::Size(855, 97);
            this->label93->TabIndex = 218;
            this->label93->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label94
            // 
            this->label94->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label94->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label94->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label94->Location = System::Drawing::Point(873, 8074);
            this->label94->Name = L"label94";
            this->label94->Size = System::Drawing::Size(254, 97);
            this->label94->TabIndex = 216;
            this->label94->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox48
            // 
            this->checkBox48->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox48.BackgroundImage")));
            this->checkBox48->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox48->Location = System::Drawing::Point(1133, 8248);
            this->checkBox48->Name = L"checkBox48";
            this->checkBox48->Size = System::Drawing::Size(159, 97);
            this->checkBox48->TabIndex = 223;
            this->checkBox48->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox48->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox48->UseVisualStyleBackColor = true;
            this->checkBox48->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox48_CheckedChanged);
            // 
            // label95
            // 
            this->label95->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label95->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label95->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label95->Location = System::Drawing::Point(12, 8248);
            this->label95->Name = L"label95";
            this->label95->Size = System::Drawing::Size(855, 97);
            this->label95->TabIndex = 222;
            this->label95->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label96
            // 
            this->label96->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label96->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label96->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label96->Location = System::Drawing::Point(873, 8248);
            this->label96->Name = L"label96";
            this->label96->Size = System::Drawing::Size(254, 97);
            this->label96->TabIndex = 220;
            this->label96->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox49
            // 
            this->checkBox49->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox49.BackgroundImage")));
            this->checkBox49->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox49->Location = System::Drawing::Point(1133, 8422);
            this->checkBox49->Name = L"checkBox49";
            this->checkBox49->Size = System::Drawing::Size(159, 97);
            this->checkBox49->TabIndex = 227;
            this->checkBox49->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox49->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox49->UseVisualStyleBackColor = true;
            this->checkBox49->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox49_CheckedChanged);
            // 
            // label97
            // 
            this->label97->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label97->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label97->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label97->Location = System::Drawing::Point(12, 8422);
            this->label97->Name = L"label97";
            this->label97->Size = System::Drawing::Size(855, 97);
            this->label97->TabIndex = 226;
            this->label97->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label98
            // 
            this->label98->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label98->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label98->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label98->Location = System::Drawing::Point(873, 8422);
            this->label98->Name = L"label98";
            this->label98->Size = System::Drawing::Size(254, 97);
            this->label98->TabIndex = 224;
            this->label98->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox50
            // 
            this->checkBox50->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox50.BackgroundImage")));
            this->checkBox50->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox50->Location = System::Drawing::Point(1133, 8596);
            this->checkBox50->Name = L"checkBox50";
            this->checkBox50->Size = System::Drawing::Size(159, 97);
            this->checkBox50->TabIndex = 231;
            this->checkBox50->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox50->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox50->UseVisualStyleBackColor = true;
            this->checkBox50->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox50_CheckedChanged);
            // 
            // label99
            // 
            this->label99->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label99->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label99->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label99->Location = System::Drawing::Point(12, 8596);
            this->label99->Name = L"label99";
            this->label99->Size = System::Drawing::Size(855, 97);
            this->label99->TabIndex = 230;
            this->label99->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label100
            // 
            this->label100->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label100->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label100->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label100->Location = System::Drawing::Point(873, 8596);
            this->label100->Name = L"label100";
            this->label100->Size = System::Drawing::Size(254, 97);
            this->label100->TabIndex = 228;
            this->label100->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox51
            // 
            this->checkBox51->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox51.BackgroundImage")));
            this->checkBox51->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox51->Location = System::Drawing::Point(1133, 8770);
            this->checkBox51->Name = L"checkBox51";
            this->checkBox51->Size = System::Drawing::Size(159, 97);
            this->checkBox51->TabIndex = 235;
            this->checkBox51->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox51->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox51->UseVisualStyleBackColor = true;
            this->checkBox51->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox51_CheckedChanged);
            // 
            // label101
            // 
            this->label101->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label101->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label101->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label101->Location = System::Drawing::Point(12, 8770);
            this->label101->Name = L"label101";
            this->label101->Size = System::Drawing::Size(855, 97);
            this->label101->TabIndex = 234;
            this->label101->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label102
            // 
            this->label102->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label102->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label102->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label102->Location = System::Drawing::Point(873, 8770);
            this->label102->Name = L"label102";
            this->label102->Size = System::Drawing::Size(254, 97);
            this->label102->TabIndex = 232;
            this->label102->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox52
            // 
            this->checkBox52->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox52.BackgroundImage")));
            this->checkBox52->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox52->Location = System::Drawing::Point(1133, 8944);
            this->checkBox52->Name = L"checkBox52";
            this->checkBox52->Size = System::Drawing::Size(159, 97);
            this->checkBox52->TabIndex = 239;
            this->checkBox52->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox52->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox52->UseVisualStyleBackColor = true;
            this->checkBox52->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox52_CheckedChanged);
            // 
            // label103
            // 
            this->label103->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label103->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label103->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label103->Location = System::Drawing::Point(12, 8944);
            this->label103->Name = L"label103";
            this->label103->Size = System::Drawing::Size(855, 97);
            this->label103->TabIndex = 238;
            this->label103->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label104
            // 
            this->label104->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label104->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label104->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label104->Location = System::Drawing::Point(873, 8944);
            this->label104->Name = L"label104";
            this->label104->Size = System::Drawing::Size(254, 97);
            this->label104->TabIndex = 236;
            this->label104->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox53
            // 
            this->checkBox53->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox53.BackgroundImage")));
            this->checkBox53->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox53->Location = System::Drawing::Point(1133, 9118);
            this->checkBox53->Name = L"checkBox53";
            this->checkBox53->Size = System::Drawing::Size(159, 97);
            this->checkBox53->TabIndex = 243;
            this->checkBox53->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox53->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox53->UseVisualStyleBackColor = true;
            this->checkBox53->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox53_CheckedChanged);
            // 
            // label105
            // 
            this->label105->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label105->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label105->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label105->Location = System::Drawing::Point(12, 9118);
            this->label105->Name = L"label105";
            this->label105->Size = System::Drawing::Size(855, 97);
            this->label105->TabIndex = 242;
            this->label105->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label106
            // 
            this->label106->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label106->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label106->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label106->Location = System::Drawing::Point(873, 9118);
            this->label106->Name = L"label106";
            this->label106->Size = System::Drawing::Size(254, 97);
            this->label106->TabIndex = 240;
            this->label106->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox54
            // 
            this->checkBox54->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox54.BackgroundImage")));
            this->checkBox54->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox54->Location = System::Drawing::Point(1133, 9292);
            this->checkBox54->Name = L"checkBox54";
            this->checkBox54->Size = System::Drawing::Size(159, 97);
            this->checkBox54->TabIndex = 247;
            this->checkBox54->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox54->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox54->UseVisualStyleBackColor = true;
            this->checkBox54->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox54_CheckedChanged);
            // 
            // label107
            // 
            this->label107->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label107->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label107->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label107->Location = System::Drawing::Point(12, 9292);
            this->label107->Name = L"label107";
            this->label107->Size = System::Drawing::Size(855, 97);
            this->label107->TabIndex = 246;
            this->label107->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label108
            // 
            this->label108->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label108->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label108->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label108->Location = System::Drawing::Point(873, 9292);
            this->label108->Name = L"label108";
            this->label108->Size = System::Drawing::Size(254, 97);
            this->label108->TabIndex = 244;
            this->label108->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox55
            // 
            this->checkBox55->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox55.BackgroundImage")));
            this->checkBox55->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox55->Location = System::Drawing::Point(1133, 9466);
            this->checkBox55->Name = L"checkBox55";
            this->checkBox55->Size = System::Drawing::Size(159, 97);
            this->checkBox55->TabIndex = 251;
            this->checkBox55->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox55->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox55->UseVisualStyleBackColor = true;
            this->checkBox55->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox55_CheckedChanged);
            // 
            // label109
            // 
            this->label109->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label109->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label109->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label109->Location = System::Drawing::Point(12, 9466);
            this->label109->Name = L"label109";
            this->label109->Size = System::Drawing::Size(855, 97);
            this->label109->TabIndex = 250;
            this->label109->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label110
            // 
            this->label110->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label110->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label110->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label110->Location = System::Drawing::Point(873, 9466);
            this->label110->Name = L"label110";
            this->label110->Size = System::Drawing::Size(254, 97);
            this->label110->TabIndex = 248;
            this->label110->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox56
            // 
            this->checkBox56->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox56.BackgroundImage")));
            this->checkBox56->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox56->Location = System::Drawing::Point(1133, 9640);
            this->checkBox56->Name = L"checkBox56";
            this->checkBox56->Size = System::Drawing::Size(159, 97);
            this->checkBox56->TabIndex = 255;
            this->checkBox56->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox56->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox56->UseVisualStyleBackColor = true;
            this->checkBox56->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox56_CheckedChanged);
            // 
            // label111
            // 
            this->label111->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label111->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label111->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label111->Location = System::Drawing::Point(12, 9640);
            this->label111->Name = L"label111";
            this->label111->Size = System::Drawing::Size(855, 97);
            this->label111->TabIndex = 254;
            this->label111->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label112
            // 
            this->label112->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label112->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label112->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label112->Location = System::Drawing::Point(873, 9640);
            this->label112->Name = L"label112";
            this->label112->Size = System::Drawing::Size(254, 97);
            this->label112->TabIndex = 252;
            this->label112->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox57
            // 
            this->checkBox57->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox57.BackgroundImage")));
            this->checkBox57->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox57->Location = System::Drawing::Point(1133, 9814);
            this->checkBox57->Name = L"checkBox57";
            this->checkBox57->Size = System::Drawing::Size(159, 97);
            this->checkBox57->TabIndex = 259;
            this->checkBox57->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox57->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox57->UseVisualStyleBackColor = true;
            this->checkBox57->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox57_CheckedChanged);
            // 
            // label113
            // 
            this->label113->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label113->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label113->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label113->Location = System::Drawing::Point(12, 9814);
            this->label113->Name = L"label113";
            this->label113->Size = System::Drawing::Size(855, 97);
            this->label113->TabIndex = 258;
            this->label113->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label114
            // 
            this->label114->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label114->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label114->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label114->Location = System::Drawing::Point(873, 9814);
            this->label114->Name = L"label114";
            this->label114->Size = System::Drawing::Size(254, 97);
            this->label114->TabIndex = 256;
            this->label114->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox58
            // 
            this->checkBox58->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox58.BackgroundImage")));
            this->checkBox58->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox58->Location = System::Drawing::Point(1133, 9988);
            this->checkBox58->Name = L"checkBox58";
            this->checkBox58->Size = System::Drawing::Size(159, 97);
            this->checkBox58->TabIndex = 263;
            this->checkBox58->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox58->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox58->UseVisualStyleBackColor = true;
            this->checkBox58->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox58_CheckedChanged);
            // 
            // label115
            // 
            this->label115->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label115->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label115->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label115->Location = System::Drawing::Point(12, 9988);
            this->label115->Name = L"label115";
            this->label115->Size = System::Drawing::Size(855, 97);
            this->label115->TabIndex = 262;
            this->label115->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label116
            // 
            this->label116->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label116->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label116->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label116->Location = System::Drawing::Point(873, 9988);
            this->label116->Name = L"label116";
            this->label116->Size = System::Drawing::Size(254, 97);
            this->label116->TabIndex = 260;
            this->label116->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox59
            // 
            this->checkBox59->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox59.BackgroundImage")));
            this->checkBox59->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox59->Location = System::Drawing::Point(1133, 10162);
            this->checkBox59->Name = L"checkBox59";
            this->checkBox59->Size = System::Drawing::Size(159, 97);
            this->checkBox59->TabIndex = 267;
            this->checkBox59->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox59->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox59->UseVisualStyleBackColor = true;
            this->checkBox59->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox59_CheckedChanged);
            // 
            // label117
            // 
            this->label117->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label117->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label117->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label117->Location = System::Drawing::Point(12, 10162);
            this->label117->Name = L"label117";
            this->label117->Size = System::Drawing::Size(855, 97);
            this->label117->TabIndex = 266;
            this->label117->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label118
            // 
            this->label118->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label118->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label118->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label118->Location = System::Drawing::Point(873, 10162);
            this->label118->Name = L"label118";
            this->label118->Size = System::Drawing::Size(254, 97);
            this->label118->TabIndex = 264;
            this->label118->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox60
            // 
            this->checkBox60->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox60.BackgroundImage")));
            this->checkBox60->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox60->Location = System::Drawing::Point(1133, 10336);
            this->checkBox60->Name = L"checkBox60";
            this->checkBox60->Size = System::Drawing::Size(159, 97);
            this->checkBox60->TabIndex = 271;
            this->checkBox60->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox60->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox60->UseVisualStyleBackColor = true;
            this->checkBox60->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox60_CheckedChanged);
            // 
            // label119
            // 
            this->label119->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label119->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label119->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label119->Location = System::Drawing::Point(12, 10336);
            this->label119->Name = L"label119";
            this->label119->Size = System::Drawing::Size(855, 97);
            this->label119->TabIndex = 270;
            this->label119->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label120
            // 
            this->label120->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label120->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label120->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label120->Location = System::Drawing::Point(873, 10336);
            this->label120->Name = L"label120";
            this->label120->Size = System::Drawing::Size(254, 97);
            this->label120->TabIndex = 268;
            this->label120->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox61
            // 
            this->checkBox61->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox61.BackgroundImage")));
            this->checkBox61->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox61->Location = System::Drawing::Point(1133, 10510);
            this->checkBox61->Name = L"checkBox61";
            this->checkBox61->Size = System::Drawing::Size(159, 97);
            this->checkBox61->TabIndex = 275;
            this->checkBox61->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox61->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox61->UseVisualStyleBackColor = true;
            this->checkBox61->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox61_CheckedChanged);
            // 
            // label121
            // 
            this->label121->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label121->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label121->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label121->Location = System::Drawing::Point(12, 10510);
            this->label121->Name = L"label121";
            this->label121->Size = System::Drawing::Size(855, 97);
            this->label121->TabIndex = 274;
            this->label121->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label122
            // 
            this->label122->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label122->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label122->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label122->Location = System::Drawing::Point(873, 10510);
            this->label122->Name = L"label122";
            this->label122->Size = System::Drawing::Size(254, 97);
            this->label122->TabIndex = 272;
            this->label122->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox62
            // 
            this->checkBox62->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox62.BackgroundImage")));
            this->checkBox62->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox62->Location = System::Drawing::Point(1133, 10684);
            this->checkBox62->Name = L"checkBox62";
            this->checkBox62->Size = System::Drawing::Size(159, 97);
            this->checkBox62->TabIndex = 279;
            this->checkBox62->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox62->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox62->UseVisualStyleBackColor = true;
            this->checkBox62->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox62_CheckedChanged);
            // 
            // label123
            // 
            this->label123->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label123->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label123->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label123->Location = System::Drawing::Point(12, 10684);
            this->label123->Name = L"label123";
            this->label123->Size = System::Drawing::Size(855, 97);
            this->label123->TabIndex = 278;
            this->label123->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label124
            // 
            this->label124->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label124->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label124->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label124->Location = System::Drawing::Point(873, 10684);
            this->label124->Name = L"label124";
            this->label124->Size = System::Drawing::Size(254, 97);
            this->label124->TabIndex = 276;
            this->label124->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox63
            // 
            this->checkBox63->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox63.BackgroundImage")));
            this->checkBox63->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox63->Location = System::Drawing::Point(1133, 10858);
            this->checkBox63->Name = L"checkBox63";
            this->checkBox63->Size = System::Drawing::Size(159, 97);
            this->checkBox63->TabIndex = 283;
            this->checkBox63->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox63->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox63->UseVisualStyleBackColor = true;
            this->checkBox63->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox63_CheckedChanged);
            // 
            // label125
            // 
            this->label125->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label125->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label125->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label125->Location = System::Drawing::Point(12, 10858);
            this->label125->Name = L"label125";
            this->label125->Size = System::Drawing::Size(855, 97);
            this->label125->TabIndex = 282;
            this->label125->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label126
            // 
            this->label126->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label126->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label126->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label126->Location = System::Drawing::Point(873, 10858);
            this->label126->Name = L"label126";
            this->label126->Size = System::Drawing::Size(254, 97);
            this->label126->TabIndex = 280;
            this->label126->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox64
            // 
            this->checkBox64->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox64.BackgroundImage")));
            this->checkBox64->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox64->Location = System::Drawing::Point(1133, 11032);
            this->checkBox64->Name = L"checkBox64";
            this->checkBox64->Size = System::Drawing::Size(159, 97);
            this->checkBox64->TabIndex = 287;
            this->checkBox64->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox64->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox64->UseVisualStyleBackColor = true;
            this->checkBox64->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox64_CheckedChanged);
            // 
            // label127
            // 
            this->label127->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label127->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label127->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label127->Location = System::Drawing::Point(12, 11032);
            this->label127->Name = L"label127";
            this->label127->Size = System::Drawing::Size(855, 97);
            this->label127->TabIndex = 286;
            this->label127->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label128
            // 
            this->label128->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label128->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label128->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label128->Location = System::Drawing::Point(873, 11032);
            this->label128->Name = L"label128";
            this->label128->Size = System::Drawing::Size(254, 97);
            this->label128->TabIndex = 284;
            this->label128->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox65
            // 
            this->checkBox65->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox65.BackgroundImage")));
            this->checkBox65->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox65->Location = System::Drawing::Point(1133, 11206);
            this->checkBox65->Name = L"checkBox65";
            this->checkBox65->Size = System::Drawing::Size(159, 97);
            this->checkBox65->TabIndex = 291;
            this->checkBox65->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox65->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox65->UseVisualStyleBackColor = true;
            this->checkBox65->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox65_CheckedChanged);
            // 
            // label129
            // 
            this->label129->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label129->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label129->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label129->Location = System::Drawing::Point(12, 11206);
            this->label129->Name = L"label129";
            this->label129->Size = System::Drawing::Size(855, 97);
            this->label129->TabIndex = 290;
            this->label129->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label130
            // 
            this->label130->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label130->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label130->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label130->Location = System::Drawing::Point(873, 11206);
            this->label130->Name = L"label130";
            this->label130->Size = System::Drawing::Size(254, 97);
            this->label130->TabIndex = 288;
            this->label130->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox66
            // 
            this->checkBox66->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox66.BackgroundImage")));
            this->checkBox66->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox66->Location = System::Drawing::Point(1133, 11380);
            this->checkBox66->Name = L"checkBox66";
            this->checkBox66->Size = System::Drawing::Size(159, 97);
            this->checkBox66->TabIndex = 295;
            this->checkBox66->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox66->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox66->UseVisualStyleBackColor = true;
            this->checkBox66->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox66_CheckedChanged);
            // 
            // label131
            // 
            this->label131->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label131->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label131->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label131->Location = System::Drawing::Point(12, 11380);
            this->label131->Name = L"label131";
            this->label131->Size = System::Drawing::Size(855, 97);
            this->label131->TabIndex = 294;
            this->label131->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label132
            // 
            this->label132->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label132->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label132->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label132->Location = System::Drawing::Point(873, 11380);
            this->label132->Name = L"label132";
            this->label132->Size = System::Drawing::Size(254, 97);
            this->label132->TabIndex = 292;
            this->label132->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox67
            // 
            this->checkBox67->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox67.BackgroundImage")));
            this->checkBox67->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox67->Location = System::Drawing::Point(1133, 11554);
            this->checkBox67->Name = L"checkBox67";
            this->checkBox67->Size = System::Drawing::Size(159, 97);
            this->checkBox67->TabIndex = 299;
            this->checkBox67->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox67->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox67->UseVisualStyleBackColor = true;
            this->checkBox67->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox67_CheckedChanged);
            // 
            // label133
            // 
            this->label133->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label133->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label133->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label133->Location = System::Drawing::Point(12, 11554);
            this->label133->Name = L"label133";
            this->label133->Size = System::Drawing::Size(855, 97);
            this->label133->TabIndex = 298;
            this->label133->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label134
            // 
            this->label134->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label134->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label134->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label134->Location = System::Drawing::Point(873, 11554);
            this->label134->Name = L"label134";
            this->label134->Size = System::Drawing::Size(254, 97);
            this->label134->TabIndex = 296;
            this->label134->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox68
            // 
            this->checkBox68->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox68.BackgroundImage")));
            this->checkBox68->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox68->Location = System::Drawing::Point(1133, 11728);
            this->checkBox68->Name = L"checkBox68";
            this->checkBox68->Size = System::Drawing::Size(159, 97);
            this->checkBox68->TabIndex = 303;
            this->checkBox68->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox68->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox68->UseVisualStyleBackColor = true;
            this->checkBox68->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox68_CheckedChanged);
            // 
            // label135
            // 
            this->label135->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label135->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label135->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label135->Location = System::Drawing::Point(12, 11728);
            this->label135->Name = L"label135";
            this->label135->Size = System::Drawing::Size(855, 97);
            this->label135->TabIndex = 302;
            this->label135->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label136
            // 
            this->label136->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label136->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label136->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label136->Location = System::Drawing::Point(873, 11728);
            this->label136->Name = L"label136";
            this->label136->Size = System::Drawing::Size(254, 97);
            this->label136->TabIndex = 300;
            this->label136->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox69
            // 
            this->checkBox69->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox69.BackgroundImage")));
            this->checkBox69->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox69->Location = System::Drawing::Point(1133, 11902);
            this->checkBox69->Name = L"checkBox69";
            this->checkBox69->Size = System::Drawing::Size(159, 97);
            this->checkBox69->TabIndex = 307;
            this->checkBox69->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox69->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox69->UseVisualStyleBackColor = true;
            this->checkBox69->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox69_CheckedChanged);
            // 
            // label137
            // 
            this->label137->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label137->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label137->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label137->Location = System::Drawing::Point(12, 11902);
            this->label137->Name = L"label137";
            this->label137->Size = System::Drawing::Size(855, 97);
            this->label137->TabIndex = 306;
            this->label137->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label138
            // 
            this->label138->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label138->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label138->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label138->Location = System::Drawing::Point(873, 11902);
            this->label138->Name = L"label138";
            this->label138->Size = System::Drawing::Size(254, 97);
            this->label138->TabIndex = 304;
            this->label138->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox70
            // 
            this->checkBox70->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox70.BackgroundImage")));
            this->checkBox70->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox70->Location = System::Drawing::Point(1133, 12076);
            this->checkBox70->Name = L"checkBox70";
            this->checkBox70->Size = System::Drawing::Size(159, 97);
            this->checkBox70->TabIndex = 311;
            this->checkBox70->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox70->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox70->UseVisualStyleBackColor = true;
            this->checkBox70->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox70_CheckedChanged);
            // 
            // label139
            // 
            this->label139->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label139->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label139->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label139->Location = System::Drawing::Point(12, 12076);
            this->label139->Name = L"label139";
            this->label139->Size = System::Drawing::Size(855, 97);
            this->label139->TabIndex = 310;
            this->label139->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label140
            // 
            this->label140->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label140->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label140->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label140->Location = System::Drawing::Point(873, 12076);
            this->label140->Name = L"label140";
            this->label140->Size = System::Drawing::Size(254, 97);
            this->label140->TabIndex = 308;
            this->label140->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox71
            // 
            this->checkBox71->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox71.BackgroundImage")));
            this->checkBox71->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox71->Location = System::Drawing::Point(1133, 12250);
            this->checkBox71->Name = L"checkBox71";
            this->checkBox71->Size = System::Drawing::Size(159, 97);
            this->checkBox71->TabIndex = 315;
            this->checkBox71->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox71->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox71->UseVisualStyleBackColor = true;
            this->checkBox71->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox71_CheckedChanged);
            // 
            // label141
            // 
            this->label141->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label141->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label141->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label141->Location = System::Drawing::Point(12, 12250);
            this->label141->Name = L"label141";
            this->label141->Size = System::Drawing::Size(855, 97);
            this->label141->TabIndex = 314;
            this->label141->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label142
            // 
            this->label142->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label142->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label142->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label142->Location = System::Drawing::Point(873, 12250);
            this->label142->Name = L"label142";
            this->label142->Size = System::Drawing::Size(254, 97);
            this->label142->TabIndex = 312;
            this->label142->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox72
            // 
            this->checkBox72->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox72.BackgroundImage")));
            this->checkBox72->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox72->Location = System::Drawing::Point(1133, 12424);
            this->checkBox72->Name = L"checkBox72";
            this->checkBox72->Size = System::Drawing::Size(159, 97);
            this->checkBox72->TabIndex = 319;
            this->checkBox72->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox72->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox72->UseVisualStyleBackColor = true;
            this->checkBox72->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox72_CheckedChanged);
            // 
            // label143
            // 
            this->label143->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label143->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label143->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label143->Location = System::Drawing::Point(12, 12424);
            this->label143->Name = L"label143";
            this->label143->Size = System::Drawing::Size(855, 97);
            this->label143->TabIndex = 318;
            this->label143->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label144
            // 
            this->label144->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label144->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label144->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label144->Location = System::Drawing::Point(873, 12424);
            this->label144->Name = L"label144";
            this->label144->Size = System::Drawing::Size(254, 97);
            this->label144->TabIndex = 316;
            this->label144->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox73
            // 
            this->checkBox73->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox73.BackgroundImage")));
            this->checkBox73->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox73->Location = System::Drawing::Point(1133, 12598);
            this->checkBox73->Name = L"checkBox73";
            this->checkBox73->Size = System::Drawing::Size(159, 97);
            this->checkBox73->TabIndex = 323;
            this->checkBox73->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox73->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox73->UseVisualStyleBackColor = true;
            this->checkBox73->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox73_CheckedChanged);
            // 
            // label145
            // 
            this->label145->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label145->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label145->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label145->Location = System::Drawing::Point(12, 12598);
            this->label145->Name = L"label145";
            this->label145->Size = System::Drawing::Size(855, 97);
            this->label145->TabIndex = 322;
            this->label145->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label146
            // 
            this->label146->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label146->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label146->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label146->Location = System::Drawing::Point(873, 12598);
            this->label146->Name = L"label146";
            this->label146->Size = System::Drawing::Size(254, 97);
            this->label146->TabIndex = 320;
            this->label146->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox74
            // 
            this->checkBox74->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox74.BackgroundImage")));
            this->checkBox74->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox74->Location = System::Drawing::Point(1133, 12772);
            this->checkBox74->Name = L"checkBox74";
            this->checkBox74->Size = System::Drawing::Size(159, 97);
            this->checkBox74->TabIndex = 327;
            this->checkBox74->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox74->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox74->UseVisualStyleBackColor = true;
            this->checkBox74->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox74_CheckedChanged);
            // 
            // label147
            // 
            this->label147->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label147->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label147->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label147->Location = System::Drawing::Point(12, 12772);
            this->label147->Name = L"label147";
            this->label147->Size = System::Drawing::Size(855, 97);
            this->label147->TabIndex = 326;
            this->label147->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label148
            // 
            this->label148->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label148->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label148->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label148->Location = System::Drawing::Point(873, 12772);
            this->label148->Name = L"label148";
            this->label148->Size = System::Drawing::Size(254, 97);
            this->label148->TabIndex = 324;
            this->label148->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox75
            // 
            this->checkBox75->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox75.BackgroundImage")));
            this->checkBox75->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox75->Location = System::Drawing::Point(1133, 12946);
            this->checkBox75->Name = L"checkBox75";
            this->checkBox75->Size = System::Drawing::Size(159, 97);
            this->checkBox75->TabIndex = 331;
            this->checkBox75->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox75->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox75->UseVisualStyleBackColor = true;
            this->checkBox75->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox75_CheckedChanged);
            // 
            // label149
            // 
            this->label149->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label149->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label149->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label149->Location = System::Drawing::Point(12, 12946);
            this->label149->Name = L"label149";
            this->label149->Size = System::Drawing::Size(855, 97);
            this->label149->TabIndex = 330;
            this->label149->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label150
            // 
            this->label150->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label150->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label150->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label150->Location = System::Drawing::Point(873, 12946);
            this->label150->Name = L"label150";
            this->label150->Size = System::Drawing::Size(254, 97);
            this->label150->TabIndex = 328;
            this->label150->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox76
            // 
            this->checkBox76->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox76.BackgroundImage")));
            this->checkBox76->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox76->Location = System::Drawing::Point(1133, 13120);
            this->checkBox76->Name = L"checkBox76";
            this->checkBox76->Size = System::Drawing::Size(159, 97);
            this->checkBox76->TabIndex = 335;
            this->checkBox76->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox76->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox76->UseVisualStyleBackColor = true;
            this->checkBox76->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox76_CheckedChanged);
            // 
            // label151
            // 
            this->label151->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label151->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label151->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label151->Location = System::Drawing::Point(12, 13120);
            this->label151->Name = L"label151";
            this->label151->Size = System::Drawing::Size(855, 97);
            this->label151->TabIndex = 334;
            this->label151->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label152
            // 
            this->label152->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label152->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label152->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label152->Location = System::Drawing::Point(873, 13120);
            this->label152->Name = L"label152";
            this->label152->Size = System::Drawing::Size(254, 97);
            this->label152->TabIndex = 332;
            this->label152->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox77
            // 
            this->checkBox77->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox77.BackgroundImage")));
            this->checkBox77->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox77->Location = System::Drawing::Point(1133, 13294);
            this->checkBox77->Name = L"checkBox77";
            this->checkBox77->Size = System::Drawing::Size(159, 97);
            this->checkBox77->TabIndex = 339;
            this->checkBox77->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox77->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox77->UseVisualStyleBackColor = true;
            this->checkBox77->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox77_CheckedChanged);
            // 
            // label153
            // 
            this->label153->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label153->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label153->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label153->Location = System::Drawing::Point(12, 13294);
            this->label153->Name = L"label153";
            this->label153->Size = System::Drawing::Size(855, 97);
            this->label153->TabIndex = 338;
            this->label153->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label154
            // 
            this->label154->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label154->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label154->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label154->Location = System::Drawing::Point(873, 13294);
            this->label154->Name = L"label154";
            this->label154->Size = System::Drawing::Size(254, 97);
            this->label154->TabIndex = 336;
            this->label154->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox78
            // 
            this->checkBox78->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox78.BackgroundImage")));
            this->checkBox78->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox78->Location = System::Drawing::Point(1133, 13468);
            this->checkBox78->Name = L"checkBox78";
            this->checkBox78->Size = System::Drawing::Size(159, 97);
            this->checkBox78->TabIndex = 343;
            this->checkBox78->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox78->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox78->UseVisualStyleBackColor = true;
            this->checkBox78->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox78_CheckedChanged);
            // 
            // label155
            // 
            this->label155->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label155->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label155->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label155->Location = System::Drawing::Point(12, 13468);
            this->label155->Name = L"label155";
            this->label155->Size = System::Drawing::Size(855, 97);
            this->label155->TabIndex = 342;
            this->label155->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label156
            // 
            this->label156->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label156->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label156->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label156->Location = System::Drawing::Point(873, 13468);
            this->label156->Name = L"label156";
            this->label156->Size = System::Drawing::Size(254, 97);
            this->label156->TabIndex = 340;
            this->label156->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox79
            // 
            this->checkBox79->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox79.BackgroundImage")));
            this->checkBox79->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox79->Location = System::Drawing::Point(1133, 13642);
            this->checkBox79->Name = L"checkBox79";
            this->checkBox79->Size = System::Drawing::Size(159, 97);
            this->checkBox79->TabIndex = 347;
            this->checkBox79->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox79->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox79->UseVisualStyleBackColor = true;
            this->checkBox79->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox79_CheckedChanged);
            // 
            // label157
            // 
            this->label157->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label157->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label157->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label157->Location = System::Drawing::Point(12, 13642);
            this->label157->Name = L"label157";
            this->label157->Size = System::Drawing::Size(855, 97);
            this->label157->TabIndex = 346;
            this->label157->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label158
            // 
            this->label158->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label158->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label158->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label158->Location = System::Drawing::Point(873, 13642);
            this->label158->Name = L"label158";
            this->label158->Size = System::Drawing::Size(254, 97);
            this->label158->TabIndex = 344;
            this->label158->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox80
            // 
            this->checkBox80->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox80.BackgroundImage")));
            this->checkBox80->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox80->Location = System::Drawing::Point(1133, 13816);
            this->checkBox80->Name = L"checkBox80";
            this->checkBox80->Size = System::Drawing::Size(159, 97);
            this->checkBox80->TabIndex = 351;
            this->checkBox80->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox80->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox80->UseVisualStyleBackColor = true;
            this->checkBox80->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox80_CheckedChanged);
            // 
            // label159
            // 
            this->label159->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label159->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label159->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label159->Location = System::Drawing::Point(12, 13816);
            this->label159->Name = L"label159";
            this->label159->Size = System::Drawing::Size(855, 97);
            this->label159->TabIndex = 350;
            this->label159->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label160
            // 
            this->label160->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label160->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label160->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label160->Location = System::Drawing::Point(873, 13816);
            this->label160->Name = L"label160";
            this->label160->Size = System::Drawing::Size(254, 97);
            this->label160->TabIndex = 348;
            this->label160->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox81
            // 
            this->checkBox81->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox81.BackgroundImage")));
            this->checkBox81->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox81->Location = System::Drawing::Point(1133, 13990);
            this->checkBox81->Name = L"checkBox81";
            this->checkBox81->Size = System::Drawing::Size(159, 97);
            this->checkBox81->TabIndex = 355;
            this->checkBox81->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox81->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox81->UseVisualStyleBackColor = true;
            this->checkBox81->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox81_CheckedChanged);
            // 
            // label161
            // 
            this->label161->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label161->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label161->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label161->Location = System::Drawing::Point(12, 13990);
            this->label161->Name = L"label161";
            this->label161->Size = System::Drawing::Size(855, 97);
            this->label161->TabIndex = 354;
            this->label161->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label162
            // 
            this->label162->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label162->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label162->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label162->Location = System::Drawing::Point(873, 13990);
            this->label162->Name = L"label162";
            this->label162->Size = System::Drawing::Size(254, 97);
            this->label162->TabIndex = 352;
            this->label162->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox82
            // 
            this->checkBox82->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox82.BackgroundImage")));
            this->checkBox82->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox82->Location = System::Drawing::Point(1133, 14164);
            this->checkBox82->Name = L"checkBox82";
            this->checkBox82->Size = System::Drawing::Size(159, 97);
            this->checkBox82->TabIndex = 359;
            this->checkBox82->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox82->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox82->UseVisualStyleBackColor = true;
            this->checkBox82->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox82_CheckedChanged);
            // 
            // label163
            // 
            this->label163->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label163->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label163->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label163->Location = System::Drawing::Point(12, 14164);
            this->label163->Name = L"label163";
            this->label163->Size = System::Drawing::Size(855, 97);
            this->label163->TabIndex = 358;
            this->label163->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label164
            // 
            this->label164->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label164->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label164->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label164->Location = System::Drawing::Point(873, 14164);
            this->label164->Name = L"label164";
            this->label164->Size = System::Drawing::Size(254, 97);
            this->label164->TabIndex = 356;
            this->label164->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox83
            // 
            this->checkBox83->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox83.BackgroundImage")));
            this->checkBox83->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox83->Location = System::Drawing::Point(1133, 14337);
            this->checkBox83->Name = L"checkBox83";
            this->checkBox83->Size = System::Drawing::Size(159, 97);
            this->checkBox83->TabIndex = 363;
            this->checkBox83->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox83->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox83->UseVisualStyleBackColor = true;
            this->checkBox83->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox83_CheckedChanged);
            // 
            // label165
            // 
            this->label165->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label165->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label165->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label165->Location = System::Drawing::Point(12, 14337);
            this->label165->Name = L"label165";
            this->label165->Size = System::Drawing::Size(855, 97);
            this->label165->TabIndex = 362;
            this->label165->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label166
            // 
            this->label166->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label166->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label166->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label166->Location = System::Drawing::Point(873, 14337);
            this->label166->Name = L"label166";
            this->label166->Size = System::Drawing::Size(254, 97);
            this->label166->TabIndex = 360;
            this->label166->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox84
            // 
            this->checkBox84->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox84.BackgroundImage")));
            this->checkBox84->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox84->Location = System::Drawing::Point(1133, 14511);
            this->checkBox84->Name = L"checkBox84";
            this->checkBox84->Size = System::Drawing::Size(159, 97);
            this->checkBox84->TabIndex = 367;
            this->checkBox84->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox84->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox84->UseVisualStyleBackColor = true;
            this->checkBox84->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox84_CheckedChanged);
            // 
            // label167
            // 
            this->label167->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label167->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label167->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label167->Location = System::Drawing::Point(12, 14511);
            this->label167->Name = L"label167";
            this->label167->Size = System::Drawing::Size(855, 97);
            this->label167->TabIndex = 366;
            this->label167->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label168
            // 
            this->label168->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label168->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label168->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label168->Location = System::Drawing::Point(873, 14511);
            this->label168->Name = L"label168";
            this->label168->Size = System::Drawing::Size(254, 97);
            this->label168->TabIndex = 364;
            this->label168->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox85
            // 
            this->checkBox85->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox85.BackgroundImage")));
            this->checkBox85->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox85->Location = System::Drawing::Point(1133, 14685);
            this->checkBox85->Name = L"checkBox85";
            this->checkBox85->Size = System::Drawing::Size(159, 97);
            this->checkBox85->TabIndex = 371;
            this->checkBox85->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox85->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox85->UseVisualStyleBackColor = true;
            this->checkBox85->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox85_CheckedChanged);
            // 
            // label169
            // 
            this->label169->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label169->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label169->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label169->Location = System::Drawing::Point(12, 14685);
            this->label169->Name = L"label169";
            this->label169->Size = System::Drawing::Size(855, 97);
            this->label169->TabIndex = 370;
            this->label169->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label170
            // 
            this->label170->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label170->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label170->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label170->Location = System::Drawing::Point(873, 14685);
            this->label170->Name = L"label170";
            this->label170->Size = System::Drawing::Size(254, 97);
            this->label170->TabIndex = 368;
            this->label170->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox86
            // 
            this->checkBox86->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox86.BackgroundImage")));
            this->checkBox86->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox86->Location = System::Drawing::Point(1133, 14859);
            this->checkBox86->Name = L"checkBox86";
            this->checkBox86->Size = System::Drawing::Size(159, 97);
            this->checkBox86->TabIndex = 375;
            this->checkBox86->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox86->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox86->UseVisualStyleBackColor = true;
            this->checkBox86->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox86_CheckedChanged);
            // 
            // label171
            // 
            this->label171->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label171->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label171->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label171->Location = System::Drawing::Point(12, 14859);
            this->label171->Name = L"label171";
            this->label171->Size = System::Drawing::Size(855, 97);
            this->label171->TabIndex = 374;
            this->label171->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label172
            // 
            this->label172->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label172->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label172->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label172->Location = System::Drawing::Point(873, 14859);
            this->label172->Name = L"label172";
            this->label172->Size = System::Drawing::Size(254, 97);
            this->label172->TabIndex = 372;
            this->label172->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox87
            // 
            this->checkBox87->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox87.BackgroundImage")));
            this->checkBox87->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox87->Location = System::Drawing::Point(1133, 15033);
            this->checkBox87->Name = L"checkBox87";
            this->checkBox87->Size = System::Drawing::Size(159, 97);
            this->checkBox87->TabIndex = 379;
            this->checkBox87->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox87->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox87->UseVisualStyleBackColor = true;
            this->checkBox87->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox87_CheckedChanged);
            // 
            // label173
            // 
            this->label173->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label173->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label173->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label173->Location = System::Drawing::Point(12, 15033);
            this->label173->Name = L"label173";
            this->label173->Size = System::Drawing::Size(855, 97);
            this->label173->TabIndex = 378;
            this->label173->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label174
            // 
            this->label174->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label174->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label174->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label174->Location = System::Drawing::Point(873, 15033);
            this->label174->Name = L"label174";
            this->label174->Size = System::Drawing::Size(254, 97);
            this->label174->TabIndex = 376;
            this->label174->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox88
            // 
            this->checkBox88->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox88.BackgroundImage")));
            this->checkBox88->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox88->Location = System::Drawing::Point(1133, 15207);
            this->checkBox88->Name = L"checkBox88";
            this->checkBox88->Size = System::Drawing::Size(159, 97);
            this->checkBox88->TabIndex = 383;
            this->checkBox88->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox88->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox88->UseVisualStyleBackColor = true;
            this->checkBox88->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox88_CheckedChanged);
            // 
            // label175
            // 
            this->label175->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label175->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label175->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label175->Location = System::Drawing::Point(12, 15207);
            this->label175->Name = L"label175";
            this->label175->Size = System::Drawing::Size(855, 97);
            this->label175->TabIndex = 382;
            this->label175->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label176
            // 
            this->label176->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label176->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label176->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label176->Location = System::Drawing::Point(873, 15207);
            this->label176->Name = L"label176";
            this->label176->Size = System::Drawing::Size(254, 97);
            this->label176->TabIndex = 380;
            this->label176->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox89
            // 
            this->checkBox89->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox89.BackgroundImage")));
            this->checkBox89->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox89->Location = System::Drawing::Point(1133, 15381);
            this->checkBox89->Name = L"checkBox89";
            this->checkBox89->Size = System::Drawing::Size(159, 97);
            this->checkBox89->TabIndex = 387;
            this->checkBox89->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox89->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox89->UseVisualStyleBackColor = true;
            this->checkBox89->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox89_CheckedChanged);
            // 
            // label177
            // 
            this->label177->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label177->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label177->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label177->Location = System::Drawing::Point(12, 15381);
            this->label177->Name = L"label177";
            this->label177->Size = System::Drawing::Size(855, 97);
            this->label177->TabIndex = 386;
            this->label177->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label178
            // 
            this->label178->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label178->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label178->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label178->Location = System::Drawing::Point(873, 15381);
            this->label178->Name = L"label178";
            this->label178->Size = System::Drawing::Size(254, 97);
            this->label178->TabIndex = 384;
            this->label178->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox90
            // 
            this->checkBox90->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox90.BackgroundImage")));
            this->checkBox90->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox90->Location = System::Drawing::Point(1133, 15555);
            this->checkBox90->Name = L"checkBox90";
            this->checkBox90->Size = System::Drawing::Size(159, 97);
            this->checkBox90->TabIndex = 391;
            this->checkBox90->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox90->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox90->UseVisualStyleBackColor = true;
            this->checkBox90->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox90_CheckedChanged);
            // 
            // label179
            // 
            this->label179->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label179->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label179->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label179->Location = System::Drawing::Point(12, 15555);
            this->label179->Name = L"label179";
            this->label179->Size = System::Drawing::Size(855, 97);
            this->label179->TabIndex = 390;
            this->label179->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label180
            // 
            this->label180->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label180->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label180->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label180->Location = System::Drawing::Point(873, 15555);
            this->label180->Name = L"label180";
            this->label180->Size = System::Drawing::Size(254, 97);
            this->label180->TabIndex = 388;
            this->label180->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox91
            // 
            this->checkBox91->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox91.BackgroundImage")));
            this->checkBox91->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox91->Location = System::Drawing::Point(1133, 15729);
            this->checkBox91->Name = L"checkBox91";
            this->checkBox91->Size = System::Drawing::Size(159, 97);
            this->checkBox91->TabIndex = 395;
            this->checkBox91->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox91->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox91->UseVisualStyleBackColor = true;
            this->checkBox91->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox91_CheckedChanged);
            // 
            // label181
            // 
            this->label181->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label181->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label181->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label181->Location = System::Drawing::Point(12, 15729);
            this->label181->Name = L"label181";
            this->label181->Size = System::Drawing::Size(855, 97);
            this->label181->TabIndex = 394;
            this->label181->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label182
            // 
            this->label182->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label182->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label182->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label182->Location = System::Drawing::Point(873, 15729);
            this->label182->Name = L"label182";
            this->label182->Size = System::Drawing::Size(254, 97);
            this->label182->TabIndex = 392;
            this->label182->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox92
            // 
            this->checkBox92->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox92.BackgroundImage")));
            this->checkBox92->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox92->Location = System::Drawing::Point(1133, 15903);
            this->checkBox92->Name = L"checkBox92";
            this->checkBox92->Size = System::Drawing::Size(159, 97);
            this->checkBox92->TabIndex = 399;
            this->checkBox92->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox92->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox92->UseVisualStyleBackColor = true;
            this->checkBox92->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox92_CheckedChanged);
            // 
            // label183
            // 
            this->label183->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label183->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label183->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label183->Location = System::Drawing::Point(12, 15903);
            this->label183->Name = L"label183";
            this->label183->Size = System::Drawing::Size(855, 97);
            this->label183->TabIndex = 398;
            this->label183->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label184
            // 
            this->label184->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label184->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label184->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label184->Location = System::Drawing::Point(873, 15903);
            this->label184->Name = L"label184";
            this->label184->Size = System::Drawing::Size(254, 97);
            this->label184->TabIndex = 396;
            this->label184->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox93
            // 
            this->checkBox93->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox93.BackgroundImage")));
            this->checkBox93->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox93->Location = System::Drawing::Point(1133, 16077);
            this->checkBox93->Name = L"checkBox93";
            this->checkBox93->Size = System::Drawing::Size(159, 97);
            this->checkBox93->TabIndex = 403;
            this->checkBox93->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox93->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox93->UseVisualStyleBackColor = true;
            this->checkBox93->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox93_CheckedChanged);
            // 
            // label185
            // 
            this->label185->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label185->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label185->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label185->Location = System::Drawing::Point(12, 16077);
            this->label185->Name = L"label185";
            this->label185->Size = System::Drawing::Size(855, 97);
            this->label185->TabIndex = 402;
            this->label185->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label186
            // 
            this->label186->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label186->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label186->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label186->Location = System::Drawing::Point(873, 16077);
            this->label186->Name = L"label186";
            this->label186->Size = System::Drawing::Size(254, 97);
            this->label186->TabIndex = 400;
            this->label186->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox94
            // 
            this->checkBox94->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox94.BackgroundImage")));
            this->checkBox94->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox94->Location = System::Drawing::Point(1133, 16251);
            this->checkBox94->Name = L"checkBox94";
            this->checkBox94->Size = System::Drawing::Size(159, 97);
            this->checkBox94->TabIndex = 407;
            this->checkBox94->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox94->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox94->UseVisualStyleBackColor = true;
            this->checkBox94->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox94_CheckedChanged);
            // 
            // label187
            // 
            this->label187->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label187->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label187->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label187->Location = System::Drawing::Point(12, 16251);
            this->label187->Name = L"label187";
            this->label187->Size = System::Drawing::Size(855, 97);
            this->label187->TabIndex = 406;
            this->label187->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label188
            // 
            this->label188->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label188->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label188->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label188->Location = System::Drawing::Point(873, 16251);
            this->label188->Name = L"label188";
            this->label188->Size = System::Drawing::Size(254, 97);
            this->label188->TabIndex = 404;
            this->label188->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox95
            // 
            this->checkBox95->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox95.BackgroundImage")));
            this->checkBox95->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox95->Location = System::Drawing::Point(1133, 16425);
            this->checkBox95->Name = L"checkBox95";
            this->checkBox95->Size = System::Drawing::Size(159, 97);
            this->checkBox95->TabIndex = 411;
            this->checkBox95->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox95->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox95->UseVisualStyleBackColor = true;
            this->checkBox95->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox95_CheckedChanged);
            // 
            // label189
            // 
            this->label189->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label189->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label189->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label189->Location = System::Drawing::Point(12, 16425);
            this->label189->Name = L"label189";
            this->label189->Size = System::Drawing::Size(855, 97);
            this->label189->TabIndex = 410;
            this->label189->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label190
            // 
            this->label190->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label190->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label190->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label190->Location = System::Drawing::Point(873, 16425);
            this->label190->Name = L"label190";
            this->label190->Size = System::Drawing::Size(254, 97);
            this->label190->TabIndex = 408;
            this->label190->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox96
            // 
            this->checkBox96->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox96.BackgroundImage")));
            this->checkBox96->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox96->Location = System::Drawing::Point(1133, 16599);
            this->checkBox96->Name = L"checkBox96";
            this->checkBox96->Size = System::Drawing::Size(159, 97);
            this->checkBox96->TabIndex = 415;
            this->checkBox96->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox96->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox96->UseVisualStyleBackColor = true;
            this->checkBox96->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox96_CheckedChanged);
            // 
            // label191
            // 
            this->label191->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label191->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label191->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label191->Location = System::Drawing::Point(16, 16599);
            this->label191->Name = L"label191";
            this->label191->Size = System::Drawing::Size(851, 97);
            this->label191->TabIndex = 414;
            this->label191->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label192
            // 
            this->label192->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label192->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label192->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label192->Location = System::Drawing::Point(873, 16599);
            this->label192->Name = L"label192";
            this->label192->Size = System::Drawing::Size(254, 97);
            this->label192->TabIndex = 412;
            this->label192->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox97
            // 
            this->checkBox97->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox97.BackgroundImage")));
            this->checkBox97->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox97->Location = System::Drawing::Point(1133, 16773);
            this->checkBox97->Name = L"checkBox97";
            this->checkBox97->Size = System::Drawing::Size(159, 97);
            this->checkBox97->TabIndex = 419;
            this->checkBox97->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox97->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox97->UseVisualStyleBackColor = true;
            this->checkBox97->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox97_CheckedChanged);
            // 
            // label193
            // 
            this->label193->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label193->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label193->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label193->Location = System::Drawing::Point(16, 16773);
            this->label193->Name = L"label193";
            this->label193->Size = System::Drawing::Size(851, 97);
            this->label193->TabIndex = 418;
            this->label193->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label194
            // 
            this->label194->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label194->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label194->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label194->Location = System::Drawing::Point(873, 16773);
            this->label194->Name = L"label194";
            this->label194->Size = System::Drawing::Size(254, 97);
            this->label194->TabIndex = 416;
            this->label194->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox98
            // 
            this->checkBox98->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox98.BackgroundImage")));
            this->checkBox98->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox98->Location = System::Drawing::Point(1133, 16947);
            this->checkBox98->Name = L"checkBox98";
            this->checkBox98->Size = System::Drawing::Size(159, 97);
            this->checkBox98->TabIndex = 423;
            this->checkBox98->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox98->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox98->UseVisualStyleBackColor = true;
            this->checkBox98->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox98_CheckedChanged);
            // 
            // label195
            // 
            this->label195->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label195->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label195->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label195->Location = System::Drawing::Point(12, 16947);
            this->label195->Name = L"label195";
            this->label195->Size = System::Drawing::Size(855, 97);
            this->label195->TabIndex = 422;
            this->label195->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label196
            // 
            this->label196->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label196->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label196->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label196->Location = System::Drawing::Point(873, 16947);
            this->label196->Name = L"label196";
            this->label196->Size = System::Drawing::Size(254, 97);
            this->label196->TabIndex = 420;
            this->label196->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox99
            // 
            this->checkBox99->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox99.BackgroundImage")));
            this->checkBox99->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox99->Location = System::Drawing::Point(1133, 17121);
            this->checkBox99->Name = L"checkBox99";
            this->checkBox99->Size = System::Drawing::Size(159, 97);
            this->checkBox99->TabIndex = 427;
            this->checkBox99->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox99->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox99->UseVisualStyleBackColor = true;
            this->checkBox99->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox99_CheckedChanged);
            // 
            // label197
            // 
            this->label197->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label197->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label197->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label197->Location = System::Drawing::Point(12, 17121);
            this->label197->Name = L"label197";
            this->label197->Size = System::Drawing::Size(855, 97);
            this->label197->TabIndex = 426;
            this->label197->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label198
            // 
            this->label198->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label198->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label198->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label198->Location = System::Drawing::Point(873, 17121);
            this->label198->Name = L"label198";
            this->label198->Size = System::Drawing::Size(254, 97);
            this->label198->TabIndex = 424;
            this->label198->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox100
            // 
            this->checkBox100->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox100.BackgroundImage")));
            this->checkBox100->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox100->Location = System::Drawing::Point(1133, 17295);
            this->checkBox100->Name = L"checkBox100";
            this->checkBox100->Size = System::Drawing::Size(159, 97);
            this->checkBox100->TabIndex = 431;
            this->checkBox100->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox100->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox100->UseVisualStyleBackColor = true;
            this->checkBox100->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox100_CheckedChanged);
            // 
            // label199
            // 
            this->label199->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label199->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label199->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->label199->Location = System::Drawing::Point(12, 17295);
            this->label199->Name = L"label199";
            this->label199->Size = System::Drawing::Size(855, 97);
            this->label199->TabIndex = 430;
            this->label199->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label200
            // 
            this->label200->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->label200->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label200->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label200->Location = System::Drawing::Point(873, 17295);
            this->label200->Name = L"label200";
            this->label200->Size = System::Drawing::Size(254, 97);
            this->label200->TabIndex = 428;
            this->label200->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // checkBox1
            // 
            this->checkBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox1.BackgroundImage")));
            this->checkBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->checkBox1->Location = System::Drawing::Point(1133, 69);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(159, 99);
            this->checkBox1->TabIndex = 432;
            this->checkBox1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->checkBox1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
            this->checkBox1->UseVisualStyleBackColor = true;
            this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox1_CheckedChanged);
            // 
            // MyForm1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoScroll = true;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->ClientSize = System::Drawing::Size(1288, 848);
            this->Controls->Add(this->checkBox1);
            this->Controls->Add(this->checkBox100);
            this->Controls->Add(this->label199);
            this->Controls->Add(this->label200);
            this->Controls->Add(this->checkBox99);
            this->Controls->Add(this->label197);
            this->Controls->Add(this->label198);
            this->Controls->Add(this->checkBox98);
            this->Controls->Add(this->label195);
            this->Controls->Add(this->label196);
            this->Controls->Add(this->checkBox97);
            this->Controls->Add(this->label193);
            this->Controls->Add(this->label194);
            this->Controls->Add(this->checkBox96);
            this->Controls->Add(this->label191);
            this->Controls->Add(this->label192);
            this->Controls->Add(this->checkBox95);
            this->Controls->Add(this->label189);
            this->Controls->Add(this->label190);
            this->Controls->Add(this->checkBox94);
            this->Controls->Add(this->label187);
            this->Controls->Add(this->label188);
            this->Controls->Add(this->checkBox93);
            this->Controls->Add(this->label185);
            this->Controls->Add(this->label186);
            this->Controls->Add(this->checkBox92);
            this->Controls->Add(this->label183);
            this->Controls->Add(this->label184);
            this->Controls->Add(this->checkBox91);
            this->Controls->Add(this->label181);
            this->Controls->Add(this->label182);
            this->Controls->Add(this->checkBox90);
            this->Controls->Add(this->label179);
            this->Controls->Add(this->label180);
            this->Controls->Add(this->checkBox89);
            this->Controls->Add(this->label177);
            this->Controls->Add(this->label178);
            this->Controls->Add(this->checkBox88);
            this->Controls->Add(this->label175);
            this->Controls->Add(this->label176);
            this->Controls->Add(this->checkBox87);
            this->Controls->Add(this->label173);
            this->Controls->Add(this->label174);
            this->Controls->Add(this->checkBox86);
            this->Controls->Add(this->label171);
            this->Controls->Add(this->label172);
            this->Controls->Add(this->checkBox85);
            this->Controls->Add(this->label169);
            this->Controls->Add(this->label170);
            this->Controls->Add(this->checkBox84);
            this->Controls->Add(this->label167);
            this->Controls->Add(this->label168);
            this->Controls->Add(this->checkBox83);
            this->Controls->Add(this->label165);
            this->Controls->Add(this->label166);
            this->Controls->Add(this->checkBox82);
            this->Controls->Add(this->label163);
            this->Controls->Add(this->label164);
            this->Controls->Add(this->checkBox81);
            this->Controls->Add(this->label161);
            this->Controls->Add(this->label162);
            this->Controls->Add(this->checkBox80);
            this->Controls->Add(this->label159);
            this->Controls->Add(this->label160);
            this->Controls->Add(this->checkBox79);
            this->Controls->Add(this->label157);
            this->Controls->Add(this->label158);
            this->Controls->Add(this->checkBox78);
            this->Controls->Add(this->label155);
            this->Controls->Add(this->label156);
            this->Controls->Add(this->checkBox77);
            this->Controls->Add(this->label153);
            this->Controls->Add(this->label154);
            this->Controls->Add(this->checkBox76);
            this->Controls->Add(this->label151);
            this->Controls->Add(this->label152);
            this->Controls->Add(this->checkBox75);
            this->Controls->Add(this->label149);
            this->Controls->Add(this->label150);
            this->Controls->Add(this->checkBox74);
            this->Controls->Add(this->label147);
            this->Controls->Add(this->label148);
            this->Controls->Add(this->checkBox73);
            this->Controls->Add(this->label145);
            this->Controls->Add(this->label146);
            this->Controls->Add(this->checkBox72);
            this->Controls->Add(this->label143);
            this->Controls->Add(this->label144);
            this->Controls->Add(this->checkBox71);
            this->Controls->Add(this->label141);
            this->Controls->Add(this->label142);
            this->Controls->Add(this->checkBox70);
            this->Controls->Add(this->label139);
            this->Controls->Add(this->label140);
            this->Controls->Add(this->checkBox69);
            this->Controls->Add(this->label137);
            this->Controls->Add(this->label138);
            this->Controls->Add(this->checkBox68);
            this->Controls->Add(this->label135);
            this->Controls->Add(this->label136);
            this->Controls->Add(this->checkBox67);
            this->Controls->Add(this->label133);
            this->Controls->Add(this->label134);
            this->Controls->Add(this->checkBox66);
            this->Controls->Add(this->label131);
            this->Controls->Add(this->label132);
            this->Controls->Add(this->checkBox65);
            this->Controls->Add(this->label129);
            this->Controls->Add(this->label130);
            this->Controls->Add(this->checkBox64);
            this->Controls->Add(this->label127);
            this->Controls->Add(this->label128);
            this->Controls->Add(this->checkBox63);
            this->Controls->Add(this->label125);
            this->Controls->Add(this->label126);
            this->Controls->Add(this->checkBox62);
            this->Controls->Add(this->label123);
            this->Controls->Add(this->label124);
            this->Controls->Add(this->checkBox61);
            this->Controls->Add(this->label121);
            this->Controls->Add(this->label122);
            this->Controls->Add(this->checkBox60);
            this->Controls->Add(this->label119);
            this->Controls->Add(this->label120);
            this->Controls->Add(this->checkBox59);
            this->Controls->Add(this->label117);
            this->Controls->Add(this->label118);
            this->Controls->Add(this->checkBox58);
            this->Controls->Add(this->label115);
            this->Controls->Add(this->label116);
            this->Controls->Add(this->checkBox57);
            this->Controls->Add(this->label113);
            this->Controls->Add(this->label114);
            this->Controls->Add(this->checkBox56);
            this->Controls->Add(this->label111);
            this->Controls->Add(this->label112);
            this->Controls->Add(this->checkBox55);
            this->Controls->Add(this->label109);
            this->Controls->Add(this->label110);
            this->Controls->Add(this->checkBox54);
            this->Controls->Add(this->label107);
            this->Controls->Add(this->label108);
            this->Controls->Add(this->checkBox53);
            this->Controls->Add(this->label105);
            this->Controls->Add(this->label106);
            this->Controls->Add(this->checkBox52);
            this->Controls->Add(this->label103);
            this->Controls->Add(this->label104);
            this->Controls->Add(this->checkBox51);
            this->Controls->Add(this->label101);
            this->Controls->Add(this->label102);
            this->Controls->Add(this->checkBox50);
            this->Controls->Add(this->label99);
            this->Controls->Add(this->label100);
            this->Controls->Add(this->checkBox49);
            this->Controls->Add(this->label97);
            this->Controls->Add(this->label98);
            this->Controls->Add(this->checkBox48);
            this->Controls->Add(this->label95);
            this->Controls->Add(this->label96);
            this->Controls->Add(this->checkBox47);
            this->Controls->Add(this->label93);
            this->Controls->Add(this->label94);
            this->Controls->Add(this->checkBox46);
            this->Controls->Add(this->label91);
            this->Controls->Add(this->label92);
            this->Controls->Add(this->checkBox45);
            this->Controls->Add(this->label89);
            this->Controls->Add(this->label90);
            this->Controls->Add(this->checkBox44);
            this->Controls->Add(this->label87);
            this->Controls->Add(this->label88);
            this->Controls->Add(this->checkBox43);
            this->Controls->Add(this->label85);
            this->Controls->Add(this->label86);
            this->Controls->Add(this->checkBox42);
            this->Controls->Add(this->label83);
            this->Controls->Add(this->label84);
            this->Controls->Add(this->checkBox41);
            this->Controls->Add(this->label81);
            this->Controls->Add(this->label82);
            this->Controls->Add(this->checkBox40);
            this->Controls->Add(this->label79);
            this->Controls->Add(this->label80);
            this->Controls->Add(this->checkBox39);
            this->Controls->Add(this->label77);
            this->Controls->Add(this->label78);
            this->Controls->Add(this->checkBox38);
            this->Controls->Add(this->label75);
            this->Controls->Add(this->label76);
            this->Controls->Add(this->checkBox37);
            this->Controls->Add(this->label73);
            this->Controls->Add(this->label74);
            this->Controls->Add(this->checkBox36);
            this->Controls->Add(this->label71);
            this->Controls->Add(this->label72);
            this->Controls->Add(this->checkBox35);
            this->Controls->Add(this->label69);
            this->Controls->Add(this->label70);
            this->Controls->Add(this->checkBox34);
            this->Controls->Add(this->label67);
            this->Controls->Add(this->label68);
            this->Controls->Add(this->checkBox33);
            this->Controls->Add(this->label65);
            this->Controls->Add(this->label66);
            this->Controls->Add(this->checkBox32);
            this->Controls->Add(this->label63);
            this->Controls->Add(this->label64);
            this->Controls->Add(this->checkBox31);
            this->Controls->Add(this->label61);
            this->Controls->Add(this->label62);
            this->Controls->Add(this->checkBox30);
            this->Controls->Add(this->label59);
            this->Controls->Add(this->label60);
            this->Controls->Add(this->checkBox29);
            this->Controls->Add(this->label57);
            this->Controls->Add(this->label58);
            this->Controls->Add(this->checkBox28);
            this->Controls->Add(this->label55);
            this->Controls->Add(this->label56);
            this->Controls->Add(this->checkBox27);
            this->Controls->Add(this->label53);
            this->Controls->Add(this->label54);
            this->Controls->Add(this->checkBox26);
            this->Controls->Add(this->label51);
            this->Controls->Add(this->label52);
            this->Controls->Add(this->checkBox25);
            this->Controls->Add(this->label49);
            this->Controls->Add(this->label50);
            this->Controls->Add(this->checkBox24);
            this->Controls->Add(this->label47);
            this->Controls->Add(this->label48);
            this->Controls->Add(this->checkBox23);
            this->Controls->Add(this->label45);
            this->Controls->Add(this->label46);
            this->Controls->Add(this->checkBox22);
            this->Controls->Add(this->label43);
            this->Controls->Add(this->label44);
            this->Controls->Add(this->checkBox21);
            this->Controls->Add(this->label41);
            this->Controls->Add(this->label42);
            this->Controls->Add(this->checkBox20);
            this->Controls->Add(this->label39);
            this->Controls->Add(this->label40);
            this->Controls->Add(this->checkBox19);
            this->Controls->Add(this->label37);
            this->Controls->Add(this->label38);
            this->Controls->Add(this->checkBox18);
            this->Controls->Add(this->label35);
            this->Controls->Add(this->label36);
            this->Controls->Add(this->checkBox17);
            this->Controls->Add(this->label33);
            this->Controls->Add(this->label34);
            this->Controls->Add(this->checkBox16);
            this->Controls->Add(this->label31);
            this->Controls->Add(this->label32);
            this->Controls->Add(this->checkBox15);
            this->Controls->Add(this->label29);
            this->Controls->Add(this->label30);
            this->Controls->Add(this->checkBox14);
            this->Controls->Add(this->label27);
            this->Controls->Add(this->label28);
            this->Controls->Add(this->checkBox13);
            this->Controls->Add(this->label25);
            this->Controls->Add(this->label26);
            this->Controls->Add(this->checkBox12);
            this->Controls->Add(this->label23);
            this->Controls->Add(this->label24);
            this->Controls->Add(this->checkBox11);
            this->Controls->Add(this->label21);
            this->Controls->Add(this->label22);
            this->Controls->Add(this->checkBox10);
            this->Controls->Add(this->label19);
            this->Controls->Add(this->label20);
            this->Controls->Add(this->checkBox9);
            this->Controls->Add(this->label17);
            this->Controls->Add(this->label18);
            this->Controls->Add(this->checkBox8);
            this->Controls->Add(this->label15);
            this->Controls->Add(this->label16);
            this->Controls->Add(this->checkBox7);
            this->Controls->Add(this->label13);
            this->Controls->Add(this->label14);
            this->Controls->Add(this->checkBox6);
            this->Controls->Add(this->label11);
            this->Controls->Add(this->label12);
            this->Controls->Add(this->checkBox5);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->checkBox4);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->checkBox3);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->checkBox2);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->buttonexit);
            this->Controls->Add(this->buttonclose);
            this->Name = L"MyForm1";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Квартиры";
            this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
            this->ResumeLayout(false);

        }
#pragma endregion

	
	private: System::Void buttonexit2_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void buttonclose_Click(System::Object^ sender, System::EventArgs^ e);

    private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e);

    private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

    private: System::Void checkBox36_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

    private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox7_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox8_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox9_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox10_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox11_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox12_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox13_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox14_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox15_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox16_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox17_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox18_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox19_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox20_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox21_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox22_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox23_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox24_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox25_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox26_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox27_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox28_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox29_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox30_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox31_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox32_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox33_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox34_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox35_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox37_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox38_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox39_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox40_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox41_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox42_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox43_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox44_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox45_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox46_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox47_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox48_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox49_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox50_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox51_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox52_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox53_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox54_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox55_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox56_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox57_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox58_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox59_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox60_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox61_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox62_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox63_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox64_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox65_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox66_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox67_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox68_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox69_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e);

private: System::Void checkBox70_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox71_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox72_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox73_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox74_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox75_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox76_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox77_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox78_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox79_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox80_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox81_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox82_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox83_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox84_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox85_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox86_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox87_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox88_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox89_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox90_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox91_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox92_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox93_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox94_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox95_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox96_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox97_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox98_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox99_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void checkBox100_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e);

};
}
