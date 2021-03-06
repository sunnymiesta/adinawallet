#pragma once

#include <QFrame>

#include <IWalletLegacy.h>

namespace Ui {
class SendMessageFrame;
}

namespace WalletGui {

class MessageAddressFrame;

class SendMessageFrame : public QFrame {
  Q_OBJECT
  Q_DISABLE_COPY(SendMessageFrame)

public:
  SendMessageFrame(QWidget* _parent);
  ~SendMessageFrame();

  void setAddress(const QString& _address);

private:
  QScopedPointer<Ui::SendMessageFrame> m_ui;
  QList<MessageAddressFrame*> m_addressFrames;
  void sendMessageCompleted(CryptoNote::TransactionId _transactionId, bool _error, const QString& _errorText);
  void reset();

  QString extractAddress(const QString& _addressString) const;
  void recalculateFeeValue();

  Q_SLOT void addRecipientClicked();
  Q_SLOT void messageTextChanged();
  Q_SLOT void mixinValueChanged(int _value);
  Q_SLOT void sendClicked();
  Q_SLOT void ttlCheckStateChanged(int _state);
  Q_SLOT void ttlValueChanged(int _ttlValue);
};

}
