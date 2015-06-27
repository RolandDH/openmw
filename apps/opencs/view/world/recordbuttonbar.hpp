#ifndef CSV_WORLD_RECORDBUTTONBAR_H
#define CSV_WORLD_RECORDBUTTONBAR_H

#include <QWidget>

#include "../../model/world/universalid.hpp"

class QToolButton;

namespace CSMWorld
{
    class IdTable;
    class CommandDispatcher;
}

namespace CSVWorld
{
    class TableBottomBox;

    /// \brief Button bar for use in dialogue-type subviews
    ///
    /// Contains the following buttons:
    /// - next/prev
    /// - clone
    /// - add
    /// - delete
    /// - revert
    /// - preview (optional)
    /// - view (optional)
    class RecordButtonBar : public QWidget
    {
            Q_OBJECT

            CSMWorld::UniversalId mId;
            CSMWorld::IdTable& mTable;
            TableBottomBox *mBottom;
            CSMWorld::CommandDispatcher *mCommandDispatcher;
            QToolButton *mCloneButton;
            QToolButton *mAddButton;
            QToolButton *mDeleteButton;
            QToolButton *mRevertButton;
            bool mLocked;

        private:

            void updateModificationButtons();
            
        public:

            RecordButtonBar (const CSMWorld::UniversalId& id,
                CSMWorld::IdTable& table, TableBottomBox *bottomBox = 0,
                CSMWorld::CommandDispatcher *commandDispatcher = 0, QWidget *parent = 0);

            void setEditLock (bool locked);
                
        public slots:

            void universalIdChanged (const CSMWorld::UniversalId& id);

        private slots:

            void cloneRequest();

            void nextId();

            void prevId();
            
        signals:

            void showPreview();

            void viewRecord();

            void switchToRow (int row);
    };
}

#endif
