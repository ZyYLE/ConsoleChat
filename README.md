# ConsoleChat  - учебная работа
        список участников команды
        - Не сложилось. Строил в одну каску. На призыв в пачке не откликнулись :) 
        
        описание выбранной идеи решения;
        - Пытался разделить логические элементы и их хранение:
        Есть класс пользователя ChatUser и структура хранения пользователей: UserBase
        Аналогично ChatMessage и MessageBase. 
        Отдльный класс элементов интерфейса ChatDisplay. 
        Таким образом меняя внутреннюю реализацию одного класса можно не трогать остальное. 

        Нет обработки исключений, нет шаблонных классов. 
        
                
        описание пользовательских типов и функций в проекте;
                class ChatUser
                Хранит Имя, Логин, Пароль, Id, привилегию
                Ко всем стандартный набор set и get функций.
                По фату id  и привидегии пока не пригодились. 

                class UserBase
                Структура хранения экземпляров ChatUser  по типу линейного аллокатора. 
                Конструктором содается массив заданного размера  UserBase(unsigned short userbasesize) с помощью  calloc 
                Если в процессе работы размера не хватает, то увеличиваем его через realloc
                  
                bool AddUser(ChatUser* chatuser);// добавление юзера в базу
                bool CheckNick(ChatUser* chatuser); //проверка свободен ли логин при регистрации
                void ListUsers();// выводсписка юзеров
                bool CheckLogin(ChatUser* chatuser); // поиск и проверка совпадения логина и пароля при входе

                class ChatMessage
        	"Сообщение"  с сопутствующими реквизитами.
                protected:
		std::string _msgbody;			// текст сообщения
		std::string _msgtime;	        	//дата время отправки
		bool _readflag;			        // флаг прочтения
		unsigned short _msgsender;		// отправитель
		unsigned short _msgreciever;	        //получатель, если 0 то всем. 
                Стандартные функци set/get и функция вывода сообщения на экран

                class MessageBase
                Хранит "ChatMessage",тоже как линейный аллокатор. 
                protected:
                unsigned short _totalmsgs; // всего сообщений в базе
                unsigned short _msgbasesize; // размер базы (вместимость) 
                ChatMessage* _startmsgPtr = nullptr; // указатель на массив сообщений
                public:
                MessageBase(unsigned short msgbasesize); //создание базы нужного размера
                virtual ~MessageBase();
                bool AddMsg(ChatMessage chatmsg); // добавление сообщения в базу
                ChatMessage GetMsg(unsigned short msgindex); // отладочная. распечатка сообщения по номеру 
                void PrintAll(); // распечатка всех сообщений
                bool FindUserMsg(ChatUser* chatuser, MessageBase* dmb); // выборка сообщений для конкретного юзера

                class ChatDisplay
                Набор диалоговых окон и передача параметров ввода по указателю
        	public:
		void ShowWelcome();
		unsigned short LoginMenu();
		unsigned short RegisterMenu(char mm, std::string* login, std::string* pass);
		unsigned short  AskLogin(char mm, std::string* login, std::string* pass);
		unsigned short  AskRegister(char mm, std::string* login, std::string* pass, std::string* fullname);
		bool RetryMenu();
		unsigned short SendRecieveLogoff();
		unsigned short SendMenu(std::string* reciever, std::string* msgbody);

