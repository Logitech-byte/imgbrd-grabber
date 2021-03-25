#ifndef SEARCH_SYNTAX_HIGHLIGHTER_H
#define SEARCH_SYNTAX_HIGHLIGHTER_H

#include <QRegularExpression>
#include <QString>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QVector>


class QTextDocument;

class SearchSyntaxHighlighter : public QSyntaxHighlighter
{
	Q_OBJECT

	public:
		explicit SearchSyntaxHighlighter(bool full, QTextDocument *parent = nullptr);

	protected:
		void highlightBlock(const QString &text) override;

	private:
		struct HighlightingRule
		{
			QRegularExpression pattern;
			QTextCharFormat format;
		};
		QVector<HighlightingRule> highlightingRules;

		QTextCharFormat favoritesFormat;
		QTextCharFormat keptForLaterFormat;
		QTextCharFormat orFormat;
		QTextCharFormat excludeFormat;
		QTextCharFormat metaFormat;
		QTextCharFormat metaOtherFormat;
		QTextCharFormat md5Format;
		QTextCharFormat urlFormat;
};

#endif // SEARCH_SYNTAX_HIGHLIGHTER_H
