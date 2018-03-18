// Copyright (c) 2011-2014 The Platinumcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PLATINUMCOINADDRESSVALIDATOR_H
#define PLATINUMCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class PlatinumcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit PlatinumcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Platinumcoin address widget validator, checks for a valid platinumcoin address.
 */
class PlatinumcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit PlatinumcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // PLATINUMCOINADDRESSVALIDATOR_H
