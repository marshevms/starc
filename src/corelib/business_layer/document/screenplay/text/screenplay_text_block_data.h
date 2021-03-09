#pragma once

#include <corelib_global.h>

#include <QModelIndex>
#include <QTextBlockUserData>


namespace BusinessLayer {
    class ScreenplayTextModelItem;
}

namespace BusinessLayer
{

class CORE_LIBRARY_EXPORT ScreenplayTextBlockData : public QTextBlockUserData
{
public:
    explicit ScreenplayTextBlockData(BusinessLayer::ScreenplayTextModelItem* _item);
    explicit ScreenplayTextBlockData(const ScreenplayTextBlockData* _other);

    BusinessLayer::ScreenplayTextModelItem* item() const;

private:
    BusinessLayer::ScreenplayTextModelItem* m_item = nullptr;
};

} // namespace Ui
