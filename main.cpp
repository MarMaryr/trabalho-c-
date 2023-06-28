#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <locale>
#include <ctype.h>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

FILE *arquivo;

void menu () {
    cout << "Listar os veiculos: 1" << endl;
    cout << "Pesquisar um veiculo: 2" << endl;
    cout << "Editar um veiculo: 3" << endl;
    cout << "Cadastrar um veiculo: 4" << endl;
    cout << "Excluir um veiculo: 5" << endl;
}

void lista () {
    ifstream arquivo;
    string linha;
    arquivo.open("veiculos.txt");
    if (arquivo.is_open()) {
        while (getline(arquivo,linha)) {
            cout << linha << endl;
        }
    } else {
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }
}

void pesquisar() {
    ifstream arquivo;
    char search[100], line[100];
    int found = 0;

    arquivo.open("veiculos.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    cout << "Realize a pesquisa: ";
    cin >> search;

    arquivo.clear();  // Limpa qualquer indicador de erro do arquivo
    arquivo.seekg(0, ios::beg);  // Retorna ao início do arquivo

    while (arquivo.getline(line, 100)) {
        if (strstr(line, search) != NULL) {
            cout << line << endl;
            found = 1;
        }
    }

    if (!found) {
        cout << "Nao encontrado." << endl;
    }

    arquivo.close();
}

void cadastrar () {
    int cont = 0;
  int c;
  char placa[7], marca[11], modelo[16], ano[5], preco[7], tipo[5], obs[21], s, N, t;
  char string[100], line[100];
  FILE *arquivo;

  arquivo = fopen("veiculos.txt", "a");
  cout << "Edite o conteúdo apertando 'a'" << endl;
  cin >>N;
  //fflush(stdin); // Limpar o buffer de entrada
  fgets(string, sizeof(string), stdin);
  fprintf(arquivo, "%s", string);
  if (N == 'A' || N == 'a') {

    cout << "Digite a placa do carro" << endl;
    fgets(placa, 8, stdin);
    placa[strcspn(placa, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", placa);

    cout << "Digite a marca" << endl;
    fgets(marca, 12, stdin);
    marca[strcspn(marca, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", marca);

    cout << "Digite o modelo" << endl;
    fgets(modelo, 17, stdin);
    modelo[strcspn(modelo, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", modelo);

    cout << "Digite o ano" << endl;
    fgets(ano, 5, stdin);
    ano[strcspn(ano, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", ano);

    getchar();

    cout << "Digite o preço" << endl;
    fgets(preco, 8, stdin);
    preco[strcspn(preco, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", preco);

    cout << "Carro ou moto" << endl;
    fgets(tipo, 6, stdin);
    tipo[strcspn(tipo, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", tipo);

    getchar();

    cout << "Alguma observação" << endl;
    cin >> s;

    //getchar();

    if (s == 'S' || s == 's') {
      cout << "Qual?" << endl;
      //for (int i = 0; obs[i] != '\n'; i++){
      getchar();
        fgets(obs, 22, stdin);
        fprintf(arquivo, "Obs: %s;", obs);
      //}
      //getchar();
    }
  }


  fclose(arquivo);

  arquivo = fopen("veiculos.txt", "r");
  while (fgets(line, sizeof(line), arquivo) != NULL) {
    if (line[0] != '\n') {
      cont++;
    }
  }
  fclose(arquivo);

  arquivo = fopen("veiculos.txt", "r+");
  // cout << "Total de carros registrados";
  cout << cont << endl;
  fprintf(arquivo, "Total de carros registrados: %d\n", cont);

  // Reposicionar o ponteiro de arquivo para o início
  fseek(arquivo, 0, SEEK_SET);

  // Copiar o conteúdo original do arquivo abaixo do contador
  while ((c = fgetc(arquivo)) != EOF) {
    fputc(c, stdout); // Exibe o conteúdo no terminal
  }

  fclose(arquivo);
}

void editar() {


     string arquivo = "veiculos.txt"; // Nome do arquivo
     ifstream file(arquivo); // Abrir o arquivo em modo de leitura

    if (!file) {
        cerr << "Erro ao abrir o arquivo." << endl;
    }

    vector<string> lines; // Vetor para armazenar as linhas

    string line;
    while (getline(file, line)) {
        // Adicionar a linha ao vetor
        lines.push_back(line);
    }

    file.close(); // Fechar o arquivo

    int lineToDelete;
    cout << "Digite o número da linha que deseja apagar: ";
    cin >> lineToDelete;

    if (lineToDelete <= 0 || lineToDelete > lines.size()) {
        cerr << "Número de linha inválido." << endl;
    }

    lines.erase(lines.begin() + lineToDelete - 1); // Apagar a linha escolhida

    ofstream outfile(arquivo); // Abrir o arquivo em modo de escrita

    if (!outfile) {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
    }

    // Escrever as linhas restantes no arquivo
    for (const auto& l : lines) {
        outfile << l << endl;
    }

    outfile.close(); // Fechar o arquivo

    cout << "Linha removida e arquivo salvo com sucesso." << endl;

}

void reescrever () {
    char placa[7], marca[11], modelo[16], ano[5], preco[7], tipo[5], obs[21], s, N, t;
    char string[100], line[100];

    arquivo = fopen("veiculos.txt", "a");
    cout << "Edite o conteúdo apertando a" << endl;
    cin >> N;
    //fflush(stdin); // Limpar o buffer de entrada
    cin.getline(string, sizeof(string));
    fprintf(arquivo, "%s", string);

    if (N == 'A' || N == 'a') {

    cout << "Digite a placa do carro:" << endl;
    fgets(placa, 8, stdin);
    placa[strcspn(placa, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", placa);

    getchar();
    cout << "Digite a marca:" << endl;
    fgets(marca, 12, stdin);
    marca[strcspn(marca, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", marca);

    cout << "Digite o modelo: \n" << endl;
    fgets(modelo, 17, stdin);
    modelo[strcspn(modelo, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", modelo);

    cout << "Digite o ano:" << endl;
    fgets(ano, 5, stdin);
    ano[strcspn(ano, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", ano);

    getchar();

    cout << "Digite o preço:" << endl;
    fgets(preco, 8, stdin);
    preco[strcspn(preco, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", preco);

    cout << "Carro ou moto?" << endl;
    fgets(tipo, 6, stdin);
    tipo[strcspn(tipo, "\n")] = '\0'; // Remover o caractere de nova linha
    fprintf(arquivo, "%s; ", tipo);

    getchar();

    cout << "Alguma observação?" << endl;
    cin >> s;

    //getchar();

    if (s == 'S' || s == 's') {
      cout << "Qual?" << endl;
      for (int i = 0; obs[i] != '\n'; i++){
        fgets(obs, 22, stdin);
        fprintf(arquivo, "%s;", obs);
      }
      //getchar();
    }
    }
}

int main  () {
    int select;
    do { select =0;
        menu ();
        cout << "Selecione a opçao" << endl;
        cin >> select;
        switch (select) {
        case 0:
            break;
        case 1:
            cout << "Listar" << endl;
            lista ();
            break;
        case 2:
            cout << "Pesquisar" << endl;
            pesquisar ();
            break;
        case 3:
            cout << "Editar" << endl;
            editar ();
            cadastrar ();
            break;
        case 4:
            cout << "Cadastrar" << endl;
            cadastrar ();
            break;
        case 5:
            cout << "Excluir" << endl;
            break;
        }
    } while (select == 0);
}
