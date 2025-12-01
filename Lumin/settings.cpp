#include "settings.h"

Settings::Settings(const User* user1,QWidget *parent)
    : QWidget{parent}
{
    this->user = user1;
    this->setStyleSheet(
        "   border: 1px solid #eeeeee;"
        "   background-color: #ffffff;"
        "   border-radius: 12px;"
        );

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QLabel* header = new QLabel("Settings");
    header->setFixedHeight(36);
    header->setStyleSheet(" font-family: 'Outfit';"
                          " border: none;"
                          " font-weight: 600;"
                          " font-size: 24px;"
                          " line-height: 150%;"
                          " letter-spacing: 0%;"
                          " color: #1b1b1b;");
    QLabel* lowHeader = new QLabel("Manage your account settings and preferences");
    lowHeader->setFixedHeight(25);
    lowHeader->setStyleSheet(" font-family: 'Outfit';"
                             " font-weight: 400;"
                             " border: none;"
                             " font-size: 16px;"
                             " line-height: 150%;"
                             " letter-spacing: 0%;"
                             " color: #838383;");

    QLabel* profileLabel = new QLabel;
    profileLabel->setFixedHeight(390);
    QVBoxLayout* profileLayout = new QVBoxLayout(profileLabel);
    QLabel* profileHeader = new QLabel("Profile Settings");
    profileHeader->setFixedHeight(27);
    profileHeader->setStyleSheet(" font-family: 'Outfit';"
                               " border: none;"
                               " font-weight: 500;"
                               " font-size: 18px;"
                               " line-height: 150%;"
                               " letter-spacing: 0%;"
                               " color: #111113;"
                               );
    QLabel* profileLowHeader = new QLabel("Update your profile information");
    profileLowHeader->setFixedHeight(20);
    profileLowHeader->setStyleSheet(" font-family: 'Outfit';"
                                  " border: none;"
                                  " font-weight: 400;"
                                  " font-size: 14px;"
                                  " line-height: 140%;"
                                  " letter-spacing: 0%;"
                                  " color: #838383;"
                                  );

    QHBoxLayout* photoLayout = new QHBoxLayout;
    QLabel* photoLabel = new QLabel;
    photoLabel->setFixedSize(72,72);
    QPushButton* photoChangeButton = new QPushButton;
    photoChangeButton->setText("Change Photo");
    photoChangeButton->setStyleSheet(" border: 1px solid #dfe1e7;"
                                     " border-radius: 8px;"
                                     " font-family: 'Outfit';"
                                     " font-weight: 500;"
                                     " font-size: 12px;"
                                     " line-height: 155%;"
                                     " letter-spacing: 0%;"
                                     " text-align: center;"
                                     " color: #111113;"
                                     );
    QPushButton* photoRemoveButton = new QPushButton;
    photoRemoveButton->setFixedSize(96,33);
    photoRemoveButton->setText("Remove Photo");
    photoRemoveButton->setStyleSheet(" border: 1px solid #dfe1e7;"
                                     " border-radius: 8px;"
                                     " font-family: 'Outfit';"
                                     " font-weight: 500;"
                                     " font-size: 12px;"
                                     " line-height: 155%;"
                                     " letter-spacing: 0%;"
                                     " text-align: center;"
                                     " color: #111113;"
                                     );
    photoRemoveButton->setDisabled(true);
    photoLayout->addWidget(photoLabel);
    photoLayout->addWidget(photoChangeButton);
    photoLayout->addWidget(photoRemoveButton);
    photoLayout->addStretch();

    QHBoxLayout* nameLayout = new QHBoxLayout;
    QVBoxLayout* firstLayout = new QVBoxLayout;
    QLabel* firstNameLabel = new QLabel("First Name");
    firstNameLabel->setStyleSheet(" font-family: 'Outfit';"
                                  " border: none;"
                                  " font-weight: 500;"
                                  " font-size: 12px;"
                                  " line-height: 155%;"
                                  " letter-spacing: 0%;"
                                  " text-align: center;"
                                  " color: #0d0d12;"
                                  );
    QLineEdit* firstNameEdit = new QLineEdit;
    firstNameEdit->setText(user->getFirstName());
    firstNameEdit->setFixedHeight(33);
    firstNameEdit->setStyleSheet(" border: 1px solid #dfe1e7;;"
                                " border-radius: 8px;"
                                " padding: 8px 12px 8px 12px;"
                                );
    firstLayout->addWidget(firstNameLabel,0,Qt::AlignLeft);
    firstLayout->addWidget(firstNameEdit);

    QVBoxLayout* lastLayout = new QVBoxLayout;
    QLabel* lastNameLabel = new QLabel("Last Name");
    lastNameLabel->setStyleSheet(" font-family: 'Outfit';"
                                 " border: none;"
                                 " font-weight: 500;"
                                 " font-size: 12px;"
                                 " line-height: 155%;"
                                 " letter-spacing: 0%;"
                                 " text-align: center;"
                                 " color: #0d0d12;"
                                 );

    QLineEdit* lastNameEdit = new QLineEdit;
    lastNameEdit->setText(user->getLastName());
    lastNameEdit->setFixedHeight(33);
    lastNameEdit->setStyleSheet(" border: 1px solid #dfe1e7;;"
                                " border-radius: 8px;"
                                " padding: 8px 12px 8px 12px;"
                                );

    lastLayout->addWidget(lastNameLabel);
    lastLayout->addWidget(lastNameEdit);
    nameLayout->addLayout(firstLayout);
    nameLayout->addLayout(lastLayout);
    QLabel* mailLabel = new QLabel("Email");
    mailLabel->setStyleSheet(" font-family: 'Outfit';"
                             " border: none;"
                             " font-weight: 500;"
                             " font-size: 12px;"
                             " line-height: 155%;"
                             " letter-spacing: 0%;"
                             " text-align: center;"
                             " color: #0d0d12;"
                             );
    QLineEdit* mailEdit = new QLineEdit;
    mailEdit->setText(user->getMail());
    mailEdit->setFixedHeight(33);
    mailEdit->setStyleSheet(" border: 1px solid #dfe1e7;;"
                            " border-radius: 8px;"
                            " padding: 8px 12px 8px 12px;"
                            );
    QPushButton* saveChangesButton = new QPushButton;
    saveChangesButton->setFixedSize(149,48);
    saveChangesButton->setText("Save Changes");
    saveChangesButton->setStyleSheet("border-radius: 8px;"
                                     "background-color: #1b1b1b;"
                                     "color: #ffffff;"
                                     "font-family: 'Outfit';"
                                     "font-size: 16px;"
                                     "font-weight: 400;"
                                     "line-height: 20px;"
                                     "letter-spacing: 1%;");
    connect(saveChangesButton,&QPushButton::clicked,[this,saveChangesButton,lastNameEdit,firstNameEdit,mailEdit](){
        if((firstNameEdit->text() != user->getFirstName() || lastNameEdit->text() != user->getLastName() ||
            mailEdit->text() != user->getMail()) && !(firstNameEdit->text().length() < 2 &&
            lastNameEdit->text().length() < 4 && mailEdit->text().length() < 8)){
            emit onSaveChangesClicked(firstNameEdit->text(),lastNameEdit->text(),mailEdit->text());
        }
    });

    profileLayout->addWidget(profileHeader);
    profileLayout->addSpacing(4);
    profileLayout->addWidget(profileLowHeader);
    profileLayout->addSpacing(16);
    profileLayout->addLayout(photoLayout);
    profileLayout->addSpacing(16);
    profileLayout->addLayout(nameLayout);
    profileLayout->addSpacing(10);
    profileLayout->addWidget(mailLabel);
    profileLayout->addSpacing(4);
    profileLayout->addWidget(mailEdit);
    profileLayout->addSpacing(16);
    profileLayout->addWidget(saveChangesButton);
    profileLayout->addStretch();

    QLabel* passwordLabel = new QLabel;
    passwordLabel->setFixedHeight(390);

    QLabel* passwordHeader = new QLabel("Change Password");
    passwordHeader->setStyleSheet(" font-family: 'Outfit';"
                                 " border: none;"
                                 " font-weight: 500;"
                                 " font-size: 18px;"
                                 " line-height: 150%;"
                                 " letter-spacing: 0%;"
                                 " color: #111113;"
                                 );
    QLabel* passwordLowHeader = new QLabel("Update your password to keep your account secure");
    passwordLowHeader->setStyleSheet(" font-family: 'Outfit';"
                                    " border: none;"
                                    " font-weight: 400;"
                                    " font-size: 14px;"
                                    " line-height: 140%;"
                                    " letter-spacing: 0%;"
                                    " color: #838383;"
                                    );


    QVBoxLayout* passwordLayout = new QVBoxLayout(passwordLabel);
    QLabel* currentPassLabel = new QLabel("Current Password");
    currentPassLabel->setStyleSheet(" font-family: 'Outfit';"
                             " border: none;"
                             " font-weight: 500;"
                             " font-size: 12px;"
                             " line-height: 155%;"
                             " letter-spacing: 0%;"
                             " text-align: center;"
                             " color: #0d0d12;"
                             );
    QLabel* newPassLabel = new QLabel("New Password");
    newPassLabel->setStyleSheet(" font-family: 'Outfit';"
                             " border: none;"
                             " font-weight: 500;"
                             " font-size: 12px;"
                             " line-height: 155%;"
                             " letter-spacing: 0%;"
                             " text-align: center;"
                             " color: #0d0d12;"
                             );
    QLabel* confirmPassLabel = new QLabel("Confirm New Password");
    confirmPassLabel->setStyleSheet(" font-family: 'Outfit';"
                             " border: none;"
                             " font-weight: 500;"
                             " font-size: 12px;"
                             " line-height: 155%;"
                             " letter-spacing: 0%;"
                             " text-align: center;"
                             " color: #0d0d12;"
                             );
    QLineEdit* currentPassEdit = new QLineEdit;
    currentPassEdit->setFixedHeight(33);
    currentPassEdit->setStyleSheet(" border: 1px solid #dfe1e7;;"
                            " border-radius: 8px;"
                            " padding: 8px 12px 8px 12px;"
                            );
    QLineEdit* newPassEdit = new QLineEdit;
    newPassEdit->setFixedHeight(33);
    newPassEdit->setStyleSheet(" border: 1px solid #dfe1e7;;"
                                   " border-radius: 8px;"
                                   " padding: 8px 12px 8px 12px;"
                                   );
    QLineEdit* confirmPassEdit = new QLineEdit;
    confirmPassEdit->setFixedHeight(33);
    confirmPassEdit->setStyleSheet(" border: 1px solid #dfe1e7;;"
                                   " border-radius: 8px;"
                                   " padding: 8px 12px 8px 12px;"
                                   );

    QPushButton* updatePasswordButton = new QPushButton;
    updatePasswordButton->setFixedSize(149,48);
    updatePasswordButton->setText("Update Password");
    updatePasswordButton->setStyleSheet("border-radius: 8px;"
                                     "background-color: #1b1b1b;"
                                     "color: #ffffff;"
                                     "font-family: 'Outfit';"
                                     "font-size: 16px;"
                                     "font-weight: 400;"
                                     "line-height: 20px;"
                                     "letter-spacing: 1%;");

    passwordLayout->addWidget(passwordHeader);
    passwordLayout->addSpacing(4);
    passwordLayout->addWidget(passwordLowHeader);
    passwordLayout->addSpacing(10);
    passwordLayout->addWidget(currentPassLabel);
    passwordLayout->addWidget(currentPassEdit);
    passwordLayout->addSpacing(10);
    passwordLayout->addWidget(newPassLabel);
    passwordLayout->addWidget(newPassEdit);
    passwordLayout->addSpacing(10);
    passwordLayout->addWidget(confirmPassLabel);
    passwordLayout->addWidget(confirmPassEdit);
    passwordLayout->addSpacing(10);
    passwordLayout->addWidget(updatePasswordButton);


    mainLayout->setContentsMargins(30,30,30,30);
    mainLayout->addWidget(header);
    mainLayout->addWidget(lowHeader);
    mainLayout->addSpacing(16);
    mainLayout->addWidget(profileLabel);
    mainLayout->addSpacing(16);
    mainLayout->addWidget(passwordLabel);

    mainLayout->addStretch();
}
