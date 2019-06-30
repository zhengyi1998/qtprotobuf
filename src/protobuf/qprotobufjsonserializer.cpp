/*
 * MIT License
 *
 * Copyright (c) 2019 Alexey Edelev <semlanik@gmail.com>
 *
 * This file is part of QtProtobuf project https://git.semlanik.org/semlanik/qtprotobuf
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "qprotobufjsonserializer.h"
#include <QMetaProperty>

using namespace QtProtobuf;

QProtobufJsonSerializer::QProtobufJsonSerializer()
{
}

QByteArray QProtobufJsonSerializer::serializeMessage(const QObject *object, const QProtobufPropertyOrdering &propertyOrdering, const QMetaObject &metaObject) const
{
    QByteArray result = "{";
    result.append(serializeObjectCommon(object, propertyOrdering, metaObject));
    result.append("}");
    return result;
}

void QProtobufJsonSerializer::deserializeMessage(QObject *object, const QByteArray &data, const QProtobufPropertyOrdering &propertyOrdering, const QMetaObject &metaObject) const
{
    Q_UNUSED(object)
    Q_UNUSED(data)
    Q_UNUSED(propertyOrdering)
    Q_UNUSED(metaObject)
}

QByteArray QProtobufJsonSerializer::serializeProperty(const QVariant &propertyValue, int fieldIndex, const QMetaProperty &metaProperty) const
{
    Q_UNUSED(fieldIndex)
    auto &value = QtProtobufPrivate::findHandler(metaProperty.userType());
    if (value.serializer) {
        return value.serializer(this, propertyValue, fieldIndex);
    } else {
        QString result("\"%1\":%2");
        return result.arg(metaProperty.name(), propertyValue.toString()).toUtf8();
    }
}

void QProtobufJsonSerializer::deserializeProperty(QObject *object, QProtobufSelfcheckIterator &it, const QProtobufPropertyOrdering &propertyOrdering, const QMetaObject &metaObject) const
{
    Q_UNUSED(object)
    Q_UNUSED(it)
    Q_UNUSED(propertyOrdering)
    Q_UNUSED(metaObject)
}

QByteArray QProtobufJsonSerializer::serializeObject(const QObject *object, const QProtobufPropertyOrdering &propertyOrdering, const QMetaObject &metaObject) const
{
    QByteArray result = "{";
    result.append(serializeObjectCommon(object, propertyOrdering, metaObject));
    result.append("}");
    return result;
}

void QProtobufJsonSerializer::deserializeObject(QObject *object, QProtobufSelfcheckIterator &it, const QProtobufPropertyOrdering &propertyOrdering, const QMetaObject &metaObject) const
{
    Q_UNUSED(object)
    Q_UNUSED(it)
    Q_UNUSED(propertyOrdering)
    Q_UNUSED(metaObject)
}

QByteArray QProtobufJsonSerializer::serializeListObject(const QObject *object, const QProtobufPropertyOrdering &propertyOrdering, const QMetaObject &metaObject, int fieldIndex) const
{
    Q_UNUSED(object)
    Q_UNUSED(propertyOrdering)
    Q_UNUSED(metaObject)
    Q_UNUSED(fieldIndex)
    return QByteArray();
}

void QProtobufJsonSerializer::deserializeListObject(QObject *object, QProtobufSelfcheckIterator &it, const QProtobufPropertyOrdering &propertyOrdering, const QMetaObject &metaObject) const
{
    Q_UNUSED(object)
    Q_UNUSED(it)
    Q_UNUSED(propertyOrdering)
    Q_UNUSED(metaObject)
}

QByteArray QProtobufJsonSerializer::serializeMapPair(const QVariant &key, const QVariant &value, int fieldIndex) const
{
    Q_UNUSED(key)
    Q_UNUSED(value)
    Q_UNUSED(fieldIndex)
    return QByteArray();
}

void QProtobufJsonSerializer::deserializeMapPair(QVariant &key, QVariant &value, QProtobufSelfcheckIterator &it) const
{
    Q_UNUSED(key)
    Q_UNUSED(value)
    Q_UNUSED(it)
}
