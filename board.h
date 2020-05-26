#ifndef BOARD_H
#define BOARD_H
#include <QAbstractListModel>
#include <vector>

class Board : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int dumension READ dimension CONSTANT)
    Q_PROPERTY(int hiddenElementValue READ boardSize CONSTANT)
public:
    using Position = std::pair<size_t, size_t>;
    static constexpr size_t defaultBoardDimension {7};
    Board(const size_t boardDimension = defaultBoardDimension,
          QObject* parent = nullptr);

    //using tile_type = size_t; //альтернативный подход, но лучше всё завернуть в структуру
    struct Tile {
        size_t value {};
        Tile& operator=(const size_t newValue) {
            value = newValue;
            return *this;
        }
        bool operator==(const size_t other){
            return other == value;
        }
    };

    Q_INVOKABLE bool move(int index);

    size_t dimension() const;
    size_t boardSize() const;

    int rowCount(const QModelIndex& parent = QModelIndex {}) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private:
    void shuffle();
    bool isPositionValid(const size_t position) const;

    //std::vector<size_t>//не так, мы воспользуемся ООП и завернём всё в структуру:
    std::vector<Tile> m_rawBoard; //в Qt принято начинать мэмберы с буквы "m" (Венгерская нотация)
    const size_t m_dimension;
    const size_t m_boardSize;
    Position getRowCol(size_t index) const;

};

#endif // BOARD_H
