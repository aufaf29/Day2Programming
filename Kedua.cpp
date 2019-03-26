#include <iostream>
#include <queue> 

struct IDPriority{
	int ID;
	int Priority;
};

void cetak(IDPriority Data){
	std::cout << Data.ID << ' ' << Data.Priority << std::endl;
}

int main(){
	std::priority_queue<IDPriority> listx;
	std::priority_queue<IDPriority> listxSementara;
	bool kelar = false;
	while(!kelar){
		IDPriority Data;
		std::cout << "Masukkan ID dan Angka Prioritas : \n";
		std::cin >> Data.ID >> Data.Priority;
		listx.push(Data);
		listxSementara = listx;
		std::cout << "Data Terurut : \n" ;
		while (!listxSementara.empty())
		{
			cetak(listxSementara.top());
			listxSementara.pop();
		}
		std::cout << '\n';
	}
}

// cara akses list jenis struct gimana ya kak, kalau integer bisa soalnya
