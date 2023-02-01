// Copyright (c) 2011-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_OPTIONSMODEL_H
#define BITCOIN_QT_OPTIONSMODEL_H

#include "amount.h"

#include <QAbstractListModel>

QT_BEGIN_NAMESPACE
class QNetworkProxy;
QT_END_NAMESPACE

/** Interface from Qt to configuration data structure for Bitcoin client.
   To Qt, the options are presented as a list with the different options
   laid out vertically.
   This can be changed to a tree once the settings become sufficiently
   complex.
 */
class OptionsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit OptionsModel(QObject *parent = 0, bool resetSettings = false);

    enum OptionID {
        StartAtStartup,         // bool
        HideTrayIcon,           // bool
        MinimizeToTray,         // bool
        MapPortUPnP,            // bool
        MinimizeOnClose,        // bool
        ProxyUse,               // bool
        ProxyIP,                // QString
        ProxyPort,              // int
        ProxyUseTor,            // bool
        ProxyIPTor,             // QString
        ProxyPortTor,           // int
        DisplayUnit,            // BitcoinUnits::Unit
        ThirdPartyTxUrls,       // QString
        Digits,                 // QString
        Theme,                  // QString
        Language,               // QString
        CoinControlFeatures,    // bool
        ThreadsScriptVerif,     // int
        DatabaseCache,          // int
        SpendZeroConfChange,    // bool
        ShowSmartnodesTab,     // bool
        ShowAdvancedPSUI,       // bool
        ShowPrivateSendPopups,  // bool
        LowKeysWarning,         // bool
        PrivateSendRounds,      // int
        PrivateSendAmount,      // int
        PrivateSendMultiSession,// bool
        Listen,                 // bool
        OptionIDRowCount,
        IpfsUrl,                // QString
        ToolbarIconsOnly,       // bool
        ipfsUrl,                // QString
        
    };

    void Init(bool resetSettings = false);
    void Reset();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    /** Updates current unit in memory, settings and emits displayUnitChanged(newUnit) signal */
    void setDisplayUnit(const QVariant &value);
    void setDisplayCurrencyIndex(const QVariant &value);

    /* Explicit getters */
    bool getHideTrayIcon() { return fHideTrayIcon; }
    bool getMinimizeToTray() { return fMinimizeToTray; }
    bool getMinimizeOnClose() { return fMinimizeOnClose; }
    int getDisplayUnit() { return nDisplayUnit; }
    int getDisplayCurrencyIndex() const { return nDisplayCurrencyIndex; }
    QString getThirdPartyTxUrls() const { return strThirdPartyTxUrls; }
    QString getIpfsUrl() const { return strIpfsUrl; }
    bool getProxySettings(QNetworkProxy& proxy) const;
    bool getCoinControlFeatures() { return fCoinControlFeatures; }
    bool getCustomFeeFeatures() const { return fCustomFeeFeatures; }
    bool getShowAdvancedPSUI() { return fShowAdvancedPSUI; }
    bool getDarkModeEnabled() const { return fDarkModeEnabled; }
    const QString& getOverriddenByCommandLine() { return strOverriddenByCommandLine; }

    /* Restart flag helper */
    void setRestartRequired(bool fRequired);
    bool isRestartRequired();
    bool resetSettings;

private:
    /* Qt-only settings */
    bool fHideTrayIcon;
    bool fMinimizeToTray;
    bool fMinimizeOnClose;
    QString language;
    int nDisplayUnit;
    int nDisplayCurrencyIndex;
    QString strThirdPartyTxUrls;
    QString strIpfsUrl;
    bool fCoinControlFeatures;
    bool fShowAdvancedPSUI;
    
    /** YERB START*/
    bool fCustomFeeFeatures;
    bool fDarkModeEnabled;
    /** YERB END*/

    /* settings that were overridden by command-line */
    QString strOverriddenByCommandLine;

    // Add option to list of GUI options overridden through command line/config file
    void addOverriddenOption(const std::string &option);

    // Check settings version and upgrade default values if required
    void checkAndMigrate();
Q_SIGNALS:
    void displayUnitChanged(int unit);
    void displayCurrencyIndexChanged(int unit);
    void privateSendRoundsChanged();
    void privateSentAmountChanged();
    void advancedPSUIChanged(bool);
    void coinControlFeaturesChanged(bool);
    void hideTrayIconChanged(bool);
};

#endif // BITCOIN_QT_OPTIONSMODEL_H
