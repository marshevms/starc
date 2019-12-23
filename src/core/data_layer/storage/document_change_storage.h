#pragma once

#include <QScopedPointer>

class QDateTime;
class QUuid;

namespace Domain {
    class DocumentChangeObject;
}


namespace DataStorageLayer
{

/**
 * @brief Хранилище изменений документов
 */
class DocumentChangeStorage
{
public:
    ~DocumentChangeStorage();

    /**
     * @brief Сохранить документ
     */
    Domain::DocumentChangeObject* appendDocumentChange(const QUuid& _documentUuid,
        const QUuid& _uuid, const QByteArray& _undoPatch, const QByteArray& _redoPatch, const QString& _userEmail, const QString& _userName);

    /**
     * @brief Сохранить несохранённые изменения сценарии
     */
    void store();

    /**
     * @brief Очистить хранилище
     */
    void clear();

private:
    DocumentChangeStorage();
    friend class StorageFacade;

    class Implementation;
    QScopedPointer<Implementation> d;
};

} // namespace DataStorageLayer