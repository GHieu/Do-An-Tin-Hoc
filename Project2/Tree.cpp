#include<iostream>

//Sử dụng cấu trúc dữ liệu Stack
#include<stack>

//Xử lí chuỗi
#include<string.h>

//Dùng để vẽ xây dựng cây
#include<windows.h>
using namespace std;

//Định nghĩa DataType là kiểu int (số nguyên)
typedef int DataType;

//Khai báo cấu trúc struct Node
struct Node {

//Giá trị của 1 node
	DataType data;

//Con trỏ left trỏ đến Node khác dùng để lưu liên kết con trái của node hiện tại
	Node* left;

//Con trỏ left trỏ đến Node khác dùng để lưu liên kết con trái của node hiện tại
	Node* right;
};

//Định nghĩa Tree là kiểu con trỏ của 1 Node
typedef struct Node* Tree;

//Kiểm tra có phải node lá hay không
bool kiemTraNutLa(Tree root) {

//Nếu root không phải là nullptr và node con bên trái và phải là nullptr thì trả về true 
	if( root != nullptr && root->left == nullptr && root->right == nullptr)
		return true;

//Ngược lại không phải là node lá trả về false
	return false;
}

//Xử lí tiền tố
void tienTo(Tree root) {

//Nếu root không trỏ node nào thì trả về (điều kiện dừng đệ quy)
	if (root == nullptr) {
		return;
	}

//Nếu node là node lá và data là toán hạng thì sẽ in ra data của node đó
	 if (kiemTraNutLa(root) && (root->data >= 'a' && root->data <= 'z'))
		cout << " " << char(root->data) << " ";

//Nếu không nằm trong điều kiện trên thì ngược lại in ra toán tử
	else
		cout << char(root->data);

//Đệ quy node con bên trái của node hiện tại
	tienTo(root->left);
	
//Đệ quy node con bên phải của node hiện tại
	tienTo(root->right);
}

//Xử lí trung tố
void trungTo(Node* root) {

//Nếu root không trỏ node nào thì trả về (điều kiện dừng đệ quy)
	if (root == nullptr) {
		return;
	}

//Đệ quy node con bên trái của node hiện tại
	trungTo(root->left);

//Nếu node là node lá và data là toán hạng thì sẽ in ra data của node đó
	if (kiemTraNutLa(root) && (root->data >= 'a' && root->data <= 'z'))
		cout << " " << char(root->data) << " ";
	else
		cout << char(root->data);

//Đệ quy node con bên phải của node hiện tạ
	trungTo(root->right);
}

//Xử lí hậu tố
void hauTo(Node* root) {

//Nếu root không trỏ node nào thì trả về (điều kiện dừng đệ quy)
	if (root == nullptr) {
		return;
	}

//Đệ quy node con bên trái của node hiện tại
	hauTo(root->left);

//Đệ quy node con bên phải của node hiện tạ
	hauTo(root->right);

//Nếu node là node lá và data là toán hạng thì sẽ in ra data của node đó
	if (kiemTraNutLa(root) && (root->data >= 'a' && root->data <= 'z'))
		cout << " " << char(root->data) << " ";
	else
		cout << char(root->data);
}



//Kiểm tra xem cây có rỗng không
bool emptyTree(Tree root) {

//Nếu không trỏ node nào thì cây rỗng trả về true
	if (root == nullptr)
		return true;

//Ngược lại nếu nó trỏ 1 node thì là cây không rỗng trả về false
	return false;
}


//
//void makeNullNStack(stack<Tree>& a) {
//	return;
//}
//void makeNullOStack(stack<char>& b) {
//	return;
//}


//Xét độ ưu tiên toán tử
int doUuTienToanTu(char c) {

//* / có độ ưu tiên nhất nên trả về giá trị là 2
	if (c == '*' || c == '/')
		return 2;

//Rồi đến + - trả về giá trị là 1
	if (c == '+' || c == '-')
		return 1;

//Còn lại dấu ngoặc ( ) trả về 0
	return 0;
}

//Xét xem có phải là toán tử không
int checkToanTu(char c) {

//Nếu kí tự là + - * / thì trả về true
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;

//Ngược lại không phải toán từ thì trả về false
	return false;
}



//Xét xem có phải là toán hạng số hoặc toán hạng (a - z) không
int checkSo(char c) {

//Nếu toán hạng từ 0 - 9 hay từ a - z thì trả về true
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
		return true;

//Ngược lại không phải là 2 toán tử trên thì trả về false
	return false;
}

//Hàm tạo node lá giá trị là x
Tree createLeafNode(DataType x) {

//Tạo và cấp phát bộ nhớ cho con trỏ tới node mới được lưu ở biến a 
	Tree a = new Node;

//Dữ liệu của node mới được gán là x
	a->data = x;

//Con trỏ bên phải của node mới không có giá trị nên gán là null
	a->left = NULL;

//Con trỏ bên phải của node mới không có giá trị nên gán là null
	a->right = NULL;
	return a;
}


void createNode(char c, stack<Tree>* NS) {

//Tạo và cấp phát bộ nhớ cho con trỏ tới node mới được lưu ở biến a 
//Khai báo con trỏ NTren , NDuoi tới 1 node của cây
	Tree a = new Node(), NTren, NDuoi;

//Dữ liệu của node mới được gán kí tự c (toán tử và toán hạng)
	a->data = c;

//NTren gán giá trị là đỉnh của Stack rồi lấy giá trị đó ra khỏi Stack
	NTren = NS->top();
	NS->pop();

//NDuoi gán giá trị là đỉnh của Stack rồi lấy giá trị đó ra khỏi Stack
	NDuoi = NS->top();
	NS->pop();

//Lấy giá trị của NDuoi vừa lấy ra khỏi Stack ở trên và gán vào con trỏ bên trái của node mới
	a->left = NDuoi;

//Lấy giá trị của NTren vừa lấy ra khỏi Stack ở trên và gán vào con trỏ bên phải của node mới
	a->right = NTren;

//Thêm node mới vừa được tạo vào Stack
	NS->push(a);
}

//Xử lí chuỗi trung tố ra cây	
Tree createTree(char m[]) {
	int i;

//Sử dụng Stack để lưu trữ các node ở NodeStack
	stack<Tree>NS;

//Sử dụng Stack để lưu các toán tử ở OperatorStack
	stack<char>OS;

//Khai báo biến a để lưu các node
	Tree a;

//Khai báo kiểu kí tự token để lưu các kí tự
	char token;

//Duyệt từng kí tự token trong mảng m[]
	for (i = 0; i < strlen(m); i++) {
		token = m[i];

//Kiểm tra nếu kí tự là toán hạng thì tạo node lá token rồi thêm vào NodeStack
		if (checkSo(token)) {
			a = createLeafNode(token);
			NS.push(a);
		}

//Nếu kí tự token là dấu ( thì thêm vào OperatorStack
		else if (token == '(')
			OS.push(token);

//Nếu kí tự token là dấu ) tạo 1 node nội bộ với toán tử lấy từ đỉnh OperatorStack rồi duyệt đến dấu ( 
		else if (token == ')') {
			while (OS.top() != '(') {
				createNode(OS.top(), &NS);
				OS.pop();
			}

//Lấy dấu ( ra khỏi OperatorStack
			OS.pop();
		}

//Nếu kí tự token là toán tử 
		else if (checkToanTu(token)) {

//Khởi tạo giá trị biến tam
			int tam = 0;

//Nếu OperatorStack không rỗng thì gán độ ưu tiên toán tử của đỉnh OperatorStack vào biến tam
			if (!OS.empty())
				tam = doUuTienToanTu(OS.top());

//Nếu toán tử đang duyệt ở hiện tại mà bé hơn toán tử ở đỉnh OperatorStack
			while (doUuTienToanTu(token) <= tam) {

//Thì ta tạo node nội bộ với toán tử đó
				createNode(char(OS.top()), &NS);

//Rồi lấy toán tử đó ra khỏi OperatorStack
				OS.pop();

//Nếu OperatorStack rỗng thì thoát vòng lặp 
				if (OS.empty())
					break;
			}

//Thêm toán tử token đó vào OperatorStack
			OS.push(token);
		}
	}

//Nếu còn xót 1 toán tử ở OperatorStack thì tạo node nội bộ với toán tử đó rồi lấy ra khỏi OperatorStack
//Lặp cho đến khi OperatorStack rỗng
	while (!OS.empty()) {
		createNode(OS.top(), &NS);
		OS.pop();
	}

//Lấy node gốc của đỉnh NodeStack gán vào biến a rồi lấy ra khỏi NodeStack
	a = NS.top();
	NS.pop();

//Giá trị trả về là con trỏ node gốc a
	return a;
}

void gotoxy(short x, short y) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(hCon, pos);
}
void NLR(Tree t, int x, int y, int d) {
	if (t != NULL) {
		gotoxy(x, y);
	 if (kiemTraNutLa(t) && (t->data >= 'a' && t->data <= 'z'))
			cout << char(t->data);
		else
			cout << char(t->data);
	}
	if (t->left != NULL) {
		gotoxy(x + 1, y + 1);
		cout << '|';
		for (int i = x - d / 2 + 2; i <= x + 2; i++) {
			gotoxy(i, y + 2);
			cout << '-';
		}
		NLR(t->left, x - d / 2, y + 3, d / 2);
	}
	if (t->right != NULL) {
		gotoxy(x + 1, y + 1);
		cout << '|';
		for (int i = x + 2; i <= x + d / 2 + 2; i++) {
			gotoxy(i, y + 2);
			cout << '-';
		}
		NLR(t->right, x + d / 2, y + 3, d / 2);
	}
}




int main() {

//Khai báo mảng kí tự m gồm 256 kí tự để lưu biểu thức trung tố do người dùng nhập vào
	char m[256];

	while (1) {

//Nhập biểu thức trung tố dùng gets_s để đảm bảo an toàn bộ nhớ
		cout << "\nNhap bieu thuc: ";
		gets_s(m);

//Kiểm tra xem nếu kí tự cuối cùng là do người dùng nhập Enter(xuống dòng) thì gán '\0' để kết thúc chuỗi
		if (m[strlen(m) - 1] == '\n')
			m[strlen(m) - 1] = '\0';

//Kiểm tra người dùng có nhập biểu thức hay không nếu không người dùng nhập Enter sẽ thoát chương trình
		if (m[0] == '\0')
			return 0;

//Tạo ra cây BST từ biểu thức trung tố(m)
		Tree T = createTree(m);

//Dùng để vẽ hình dạng cây
		NLR(T, 40, 10, 40);
		cout << "\n\n\n\n\n\n\n\n\n\n\n";

//In ra biểu thức tiền tố
		cout << "\nBieu thuc tien to: ";
		tienTo(T);

//In ra biểu thức trung tố
		cout << "\nBieu thuc trung to: ";
		trungTo(T);

//In ra biểu thức hậu tố
		cout << "\nBieu thuc hau to: ";
		hauTo(T);
	}
	return 0;
}