#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <deque>

class FileDownloader : public QObject
{
	Q_OBJECT
public:
	explicit FileDownloader(QUrl url);
	FileDownloader();
	virtual ~FileDownloader();

	void SetUrl(QUrl url);

	QByteArray GetDownloadedData() const;

signals:

	void Finished();
	void Downloaded();
	void DownloadFailed();

private slots:

	void ReplyFinished(QNetworkReply* reply);

private:
	QUrl mUrl;
	QNetworkReply::NetworkError mError;
	QNetworkAccessManager* mManager;
	QNetworkRequest* mRequest;
	QByteArray mDownloadedData;
};

#endif