/*
 * Copyright (C) 2012 Jolla Ltd. <chris.adams@jollamobile.com>
 *
 * You may use this file under the terms of the BSD license as follows:
 *
 * "Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Nemo Mobile nor the names of its contributors
 *     may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 */

#include "authdatainterface.h"

class AuthDataInterfacePrivate
{
public:
    AuthDataInterfacePrivate(Accounts::AuthData ad) : authdata(ad) {}
    Accounts::AuthData authdata;
};

/*!
    \qmltype AuthData
    \instantiates AuthDataInterface
    \inqmlmodule org.nemomobile.accounts 1
    \brief Provides access to Identity credentials information
           associated with a ServiceAccount.

    This is intended for use by client applications who wish to
    use the credentials associated with an account to sign
    into a particular service.  An AuthData instance contains
    a snapshot of the credentials information associated with
    the account.

    The properties of an AuthData instance will NOT update
    automatically if the credentials in the database are updated
    or removed by a different process.
*/

AuthDataInterface::AuthDataInterface(const Accounts::AuthData &authdata, QObject *parent)
    : QObject(parent), d(new AuthDataInterfacePrivate(authdata))
{
}

AuthDataInterface::~AuthDataInterface()
{
    delete d;
}

/*!
    \qmlproperty int AuthData::identityIdentifier
    The id of the identity associated with the account.
    Client applications can use the ServiceAccountIdentity
    type to sign in to services enabled with the
    account from which the AuthData was retrieved.
*/

int AuthDataInterface::identityIdentifier() const
{
    return d->authdata.credentialsId();
}

/*!
    \qmlproperty string AuthData::method
    The name of the method used to authenticate with the service
*/

QString AuthDataInterface::method() const
{
    return d->authdata.method();
}

/*!
    \qmlproperty QStringList AuthData::mechanisms
    The mechanisms used to authenticate with the service
*/

QString AuthDataInterface::mechanism() const
{
    return d->authdata.mechanism();
}

/*!
    \qmlproperty QVariantMap AuthData::parameters
    The parameters used during authentication with the service.
    These parameters can be used as SessionData when creating
    an AuthSession from a ServiceAccountInterface.
*/

QVariantMap AuthDataInterface::parameters() const
{
    return d->authdata.parameters();
}

