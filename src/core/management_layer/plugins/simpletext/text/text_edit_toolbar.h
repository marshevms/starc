#pragma once

#include <ui/widgets/floating_tool_bar/floating_tool_bar.h>

class QAbstractItemModel;


namespace Ui
{

/**
 * @brief Панель инструментов редактора текста
 */
class TextEditToolbar : public FloatingToolBar
{
    Q_OBJECT

public:
    explicit TextEditToolbar(QWidget* _parent = nullptr);
    ~TextEditToolbar() override;

    /**
     * @brief Задать модель выпадающего списка типов абзацев
     */
    void setParagraphTypesModel(QAbstractItemModel* _model);

    /**
     * @brief Задать название типа текущего параграфа
     */
    void setCurrentParagraphType(const QModelIndex& _index);

    /**
     * @brief Включена ли панель быстрого форматирования
     */
    bool isFastFormatPanelVisible() const;
    void setFastFormatPanelVisible(bool _visible);

    /**
     * @brief Иконка поиска
     */
    QString searchIcon() const;

    /**
     * @brief Позиция иконки поиска
     */
    QPointF searchIconPosition() const;

    /**
     * @brief Включён ли режим рецензирования
     */
    bool isCommentsModeEnabled() const;
    void setCommentsModeEnabled(bool _enabled);

signals:
    void undoPressed();
    void redoPressed();
    void paragraphTypeChanged(const QModelIndex& _index);
    void fastFormatPanelVisibleChanged(bool _visible);
    void searchPressed();
    void commentsModeEnabledChanged(bool _enabled);

protected:
    /**
     * @brief Скрываем попап, когда фокус ушёл из виджета
     */
    void focusOutEvent(QFocusEvent* _event) override;

    /**
     * @brief Обновить переводы
     */
    void updateTranslations() override;

    /**
     * @brief Обновляем виджет при изменении дизайн системы
     */
    void designSystemChangeEvent(DesignSystemChangeEvent* _event) override;

private:
    class Implementation;
    QScopedPointer<Implementation> d;
};

} // namespace Ui