#pragma once
#ifndef TASKS_H
#define TASKS_H
#include <QVariant>
#include <QMap>
#include <cstring>
#include <QString>
#include <ctime>
#include <QJsonObject>


QVariantMap Task1();

QVariantMap Task2();

QVariantMap Task3();
/*!
 * \brief Виженер
 * \return  text и answer
 */
QVariantMap Task4();

const QString alfavit = "abcdefghijklmnopqrstuvwxyz";
QJsonObject getTaskVizh();


class Shifr {
    std::string text;
    std::string key;

 public:
    Shifr(const std::string& text, const std::string& key){
        this->text = text;
        this->key = key;
    }

    QString encrypt();

    int let_num(const char& a);

    ~Shifr() {}
};





#endif // TASKS_H
