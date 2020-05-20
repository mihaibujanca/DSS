#ifndef STACKINGPARAMETERS_H
#define STACKINGPARAMETERS_H

#include <QWidget>

enum BACKGROUNDCALIBRATIONMODE : short;
enum MULTIBITMAPPROCESSMETHOD : short;
enum PICTURETYPE : short;
class CWorkspace;
class StackSettings;
class QAction;
class QMenu;
class QValidator;

namespace Ui {
class StackingParameters;
}

class StackingParameters : public QWidget
{
    Q_OBJECT

public:
    explicit StackingParameters(QWidget *parent = nullptr);
    ~StackingParameters();
	void init(PICTURETYPE rhs);

private:
    Ui::StackingParameters *ui;
	std::unique_ptr<CWorkspace> workspace;
	StackSettings * pStackSettings;
	PICTURETYPE type;
	MULTIBITMAPPROCESSMETHOD method;
	double	kappa;
	uint	iteration;
	QString kappaSigmaTip;
	QString medianKappaSigmaTip;
	QAction * nobgCal;
	QAction * pcbgCal;
	QAction * rgbbgCal;
	QAction * bgCalOptions;
	QMenu   * backgroundCalibrationMenu;

	QValidator * darkFactorValidator;
	QValidator * iterationValidator;
	QValidator * kappaValidator;

	StackingParameters & setControls();
	StackingParameters & createActions();
	StackingParameters & createMenus();

	void setMethod(MULTIBITMAPPROCESSMETHOD method);
	void setBackgroundCalibration(BACKGROUNDCALIBRATIONMODE mode);

signals:
	void methodChanged(MULTIBITMAPPROCESSMETHOD newMethod);

private slots:
	void on_modeAverage_clicked();
	void on_modeMedian_clicked();
	void on_modeKS_clicked();
	void on_modeMKS_clicked();
	void on_modeAAWA_clicked();
	void on_modeEWA_clicked();
	void on_modeMaximum_clicked();

	void on_backgroundCalibration_clicked();
	void backgroundCalibrationOptions();

	void on_iterations_textEdited(const QString &text);
	void on_kappa_textEdited(const QString &text);

	void on_debloom_stateChanged(int);
	void on_hotPixels_stateChanged(int);
	void on_badColumns_stateChanged(int);
	void on_darkOptimisation_stateChanged(int);
	void on_useDarkFactor_stateChanged(int);
	void on_darkMultiplicationFactor_textEdited(const QString &text);







	void updateControls(MULTIBITMAPPROCESSMETHOD newMethod);

};

#endif // STACKINGPARAMETERS_H
