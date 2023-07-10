#include <iostream>
#include <locale>
#include <sstream>
#include <stack>
#include <string>

using namespace std;
string reverterPalavras(const string& entrada) {
    stack<string> palavras;
    istringstream iss(entrada);
    string palavra;

    while (iss >> palavra) {
        palavras.push(palavra);
    }

    ostringstream oss;
    while (!palavras.empty()) {
        oss << palavras.top() << " ";
        palavras.pop();
    }

    string reverso = oss.str();
    if (!reverso.empty()) {
        reverso.pop_back();
    }
    return reverso;
}
string removerCaracteresDuplicados(const string& entrada) {
    string resultado;

    for (char c : entrada) {
        if (resultado.find(c) == string::npos) {
            resultado += c;
        }
    }

    return resultado;
}
string encontrarSubstringMaisLonga(const string& entrada) {
    int tamanhoPalavra = entrada.length();
    string palindromoMaisLongo;

    int inicio = 0;
    int tamanho = 0;

    for (int i = 0; i < tamanhoPalavra; i++) {
        int esquerda = i;
        int direita = i;

        while (direita < tamanhoPalavra - 1 && entrada[direita] == entrada[direita + 1]) {
            direita++;
        }

        while (esquerda > 0 && direita < tamanhoPalavra - 1 && entrada[esquerda - 1] == entrada[direita + 1]) {
            esquerda--;
            direita++;
        }

        int novoTamanho = direita - esquerda + 1;
        if (novoTamanho > tamanho) {
            inicio = esquerda;
            tamanho = novoTamanho;
        }
    }

    return entrada.substr(inicio, tamanho);
}
string primeiraLetraMaiucula(const string& entrada) {
    string resultado = entrada;
    bool maiusculo = true;

    for (int i = 0; i < resultado.length(); i++) {
        if (maiusculo && islower(resultado[i])) {
            resultado[i] = toupper(resultado[i]);
            maiusculo = false;
        } else if (resultado[i] == '.' || resultado[i] == '?' || resultado[i] == '!') {
            maiusculo = true;
        }
    }

    return resultado;
}
string verificaAnagramaDePalindromo(const string& entrada) {
    const int TAMANHO_ALFABETO = 26;
    int frequencia[TAMANHO_ALFABETO] = {0};

    for (char c : entrada) {
        if (c >= 'a' && c <= 'z') {
            frequencia[c - 'a']++;
        }
    }

    int contagemImpar = 0;

    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (frequencia[i] % 2 != 0) {
            contagemImpar++;
        }
    }

    if (contagemImpar <= 1) {
        return "true";
    }

    return "false";
}
int main(int argc, char const* argv[]) {
    cout << "1. Reverte a ordem das palavras, mantendo a ordem das palavras." << endl;
    string input = "Hello, World! OpenAI is amazing.";
    cout << "input: " << input << endl;
    cout << "output: " << reverterPalavras(input) << endl
         << endl;

    cout << "2. Remove dos caracteres duplicados." << endl;
    input = "Hello, World!";
    cout << "input: " << input << endl;
    cout << "output: " << removerCaracteresDuplicados(input) << endl
         << endl;

    cout << "3. Encontra a substring palíndroma mais longa." << endl;
    input = "babad!";
    cout << "input: " << input << endl;
    cout << "output: " << encontrarSubstringMaisLonga(input) << endl
         << endl;

    cout << "4. Coloca a primeira letra de cada palavra maiúscula." << endl;
    input = "hello. how are you? i'm fine, thank you.";
    cout << "input: " << input << endl;
    cout << "output: " << primeiraLetraMaiucula(input) << endl
         << endl;

    cout << "5. Verifica se a string é um anagrama de palíndromo" << endl;
    input = "racecar";
    cout << "input: " << input << endl;
    cout << "output: " << verificaAnagramaDePalindromo(input) << endl
         << endl;

    return 0;
}
