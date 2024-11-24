#include "tasks.h"



QJsonObject getTaskVizh() {
    srand(time(NULL));
    QString string1, string2;
    QJsonObject dataForVizh;

    for (int i = 0; i < rand() % 10 + 5; i++) {
        string1 += alfavit[rand() % alfavit.length()];
    }
    for (int i = 0; i < rand() % 10 + 5; i++) {
        string2 += alfavit[rand() % alfavit.length()];
    }
    dataForVizh["frase"] = string1;
    dataForVizh["key"] = string2;
    return dataForVizh;
}


int Shifr::let_num(const char& a)
{
    for (int i = 0; i < alfavit.length(); i++)
    {
        if (a == alfavit[i]) return i;
    }
    return 0;
}

QString Shifr::encrypt(){
    QString result_en;
    for (int i = 0; i < this->text.length(); i++)
    {
        result_en += alfavit[(this->let_num(this->text[i]) + this->let_num(this->key[i % key.length()])) % alfavit.length()];
    }
    return result_en;
}

QVariantMap Task1() {
    QVariantMap task;

    QString text = "\t\t\tВерно ли утверждение, что:\n\n";
    text += "Всякое односвязное компактное трёхмерное многообразие без края гомеоморфно трёхмерной сфере.";
    text += "\n\n\n\ да / нет";
    task["text"] = text;
    task["answer"] = "need_check";
    return task;
}

QVariantMap Task2() {
    QVariantMap task;
    QString text = "\t\t\tВы красав(чик)ца?\n";
    text += "\n\n\n\n да / нет";

    task["text"] = text;
    task["answer"] = "need_check";
    return task;
}

QVariantMap Task3() {
    QVariantMap task;

    QString text = "\t\t\tрешите пример:\n";
    int answer = 1007;
    text += "2+8-3+2*0+10*100";
    task["text"] = text;
    task["answer"] = answer;
    return task;
}

QVariantMap Task4() {
    QVariantMap task;

    QString text = "\t\tВведите шифртекст с данными параметрами:\n";
    QString frase = getTaskVizh()["frase"].toString();
    QString key = getTaskVizh()["key"].toString();


    Shifr shifr(frase.toStdString(), key.toStdString()); // Объект для шифрования
    QString encryptedText = shifr.encrypt();

    text += "Фраза:  " + frase + "\n";
    text += "Ключ:  " + key + "\n";

    task["text"] = text;
    task["answer"] = encryptedText;

    return task;
}



QVariantMap defTask() {
    QVariantMap task;

    QString text = "Default:\n";
    text+="\tError This id Default task insert '1'";
    task["text"] = text;
    task["answer"] = 1;

    return task;
}


