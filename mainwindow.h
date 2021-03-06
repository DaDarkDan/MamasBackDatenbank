#include "iomanager.h"
#include "QVBoxLayout"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QFrame;
class QTextEdit;
class QPushButton;
class RecipeManager;
class CreatePage;
class SearchPage;
class HomePage;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QHBoxLayout* createStarEditorFrameLayout(bool editable = false);
    QTextEdit* createCustomTextEdit(const QString &value, int minH, int maxH, int minW, int maxW);
    QFrame* createCustomFrame();
    QPushButton* createCustomDeleteButton();

    void openFileWithStdProgramm(QString path);

    RecipeManager* getRm() const;
    void setRm(RecipeManager* rm);

    CreatePage *getCp() const;

    SearchPage *getSp() const;

private slots:
    //create
    void on_createSaveBtn_clicked();
    void on_createAddIngredientBtn_clicked();
    void on_addedFrameDeleteButton_clicked();
    void on_createAddKeywordBtn_clicked();
    void on_uploadImgBtn_clicked();

    //search
    void on_searchAddIngredient_clicked();
    void on_searchDeleteIngredient_clicked();
    void on_searchRecipenameTxtEdit_textChanged();

    void on_searchAddKeyword_clicked();
    void on_searchDeleteKeyword_clicked();

    void on_searchIngredientTextEdit_textChanged();

    void on_searchKeywordTextEdit_textChanged();

    void on_searchResetButton_clicked();

    void on_searchCategoryComboBox_currentIndexChanged(int index);

    void on_searchFavouriteComboBox_currentIndexChanged(int index);

    void on_searchIncludeRatingCheckBox_stateChanged(int arg1);

    void on_tabWidget_currentChanged(int index);

    void on_createRatingCheckBox_stateChanged(int arg1);

    void on_createResetBtn_clicked();

    void on_homeSetDirectoryLabel_clicked();

    void on_searchSortComboBox_currentIndexChanged(int index);

    void on_createNameTxtEdit_textChanged();

    void on_createDeleteImg_clicked();

    void on_createImageLeft_clicked();

    void on_createImgRight_clicked();

    void on_searchImageLeft_clicked();

    void on_searchImageRight_clicked();

private:
    Ui::MainWindow *ui;

    CreatePage* cp;
    SearchPage* sp;
    HomePage* hp;

    void loadSettings();

    RecipeManager* rm;
    QList<QWidget*> addedIngredientFrameList;
    QList<QWidget*> addedKeywordFrameList;

    void setupSearchPage();
    void setupCreatePage();
    void setupHomePage();

};

#endif // MAINWINDOW_H
