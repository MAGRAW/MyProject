#include "board.h"
#include <algorithm>
#include <random>

namespace  {
bool isAdjacent(const Board::Position f, const Board::Position s) {
    if (f == s) {
        return false;
    }

    const auto calcDistance = [](const size_t pos1, size_t pos2) {
        int distance = static_cast<int>(pos1);
        distance -= static_cast<int>(pos2);
        distance = std::abs(distance);
        return distance;
    };

    bool result {false};

    if(f.first == s.first) {
        int distance = calcDistance(f.second, s.second);
        if (distance == 1) {
            result = true;
        }
    } else if (f.second == s.second) {
        int  distance = calcDistance(f.first, s.first);
        if (distance == 1) {
            result = true;
        }
    }
    return result;
}
}


Board::Board(const size_t boardDimension, QObject* parent )
    : QAbstractListModel {parent},
      m_dimension {boardDimension},
      m_boardSize {m_dimension * m_dimension}
{
    //создаём последовательность
    m_rawBoard.resize(m_boardSize);
    std::iota(m_rawBoard.begin(), m_rawBoard.end(), 1);

    //перемешиваем последовательность
    shuffle();


}

bool Board::move(int index)
{
    if(!isPositionValid(static_cast<size_t>(index))) {
        return false;
    }
    //size_t row;
    //size_t column;
    //std::tie(row, column) = getRowCol(index);
    const Position elementPosition {getRowCol(index)};

    auto hiddenElementIterator = std::find(m_rawBoard.begin(), m_rawBoard.end(),
                                           boardSize()); //hidden element
    Q_ASSERT(hiddenElementIterator != m_rawBoard.end());

    Position hiddenElementPosition {getRowCol(std::distance(m_rawBoard.begin(),
                                                            hiddenElementIterator))};
    if (!isAdjacent(elementPosition, hiddenElementPosition)) {
        return false;
    }
    std::swap(hiddenElementIterator->value, m_rawBoard[index].value);
    //std::iter_swap(hiddenElementIterator, elementPosition);
    emit dataChanged(createIndex(0, 0), createIndex(m_boardSize, 0));
    return true;
}

int Board::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_rawBoard.size();
}

QVariant Board::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return {};
    }

    const int rowIndex {index.row()};
    if (!isPositionValid(rowIndex)) {
        return {};
    }
    return QVariant::fromValue(m_rawBoard[rowIndex].value);
}

Board::Position Board::getRowCol(const size_t index) const
{
    Q_ASSERT(m_dimension > 0);
    size_t row = index / m_dimension;
    size_t column = index % m_dimension;

    return std::make_pair(row, column);
}

void Board::shuffle()
{
    static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 generator(seed);

    //перемешивает
    std::shuffle(m_rawBoard.begin(), m_rawBoard.end(), generator);


}

bool Board::isPositionValid(const size_t position) const
{
    return position < m_boardSize;
}

size_t Board::boardSize() const
{
    return m_boardSize;
}

size_t Board::dimension() const
{
    return m_dimension;
}
