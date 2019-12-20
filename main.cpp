#include "fraglets.h"


// std::string alphabet = {"abcdefghijklmnopqrstuvwxyz"};

std::string alphabet = {"abcdtuvxz"};


int main(int argc, char *argv[]) {


    QApplication a(argc, argv);

    
    fraglets frag;

    // molecule mol = {"fork nop z match z split match z fork fork fork nop z * split match z fork fork fork nop z * copy z"};
    // frag.inject(mol);

    // for (int i = 0; i< 50; i++){
    //     frag.inject(mol);

    //     frag.inject({"z"});

    // }
    // molecule mol2 = {"matchp","z"};
    // std::string::iterator alphaIt2;
    // std::unordered_set<std::string>::iterator uIt;
    // for (alphaIt2 = alphabet.begin();alphaIt2!=alphabet.end();alphaIt2++){
    //     molecule newMol = mol2 + *alphaIt2;
    //     frag.inject(newMol);
    //     newMol = mol2 + "z " + *alphaIt2;
    //     frag.inject(newMol);

    // }
    // for (uIt = unimolTags.begin();uIt!=unimolTags.end();uIt++){

    //     molecule newMolTag = mol2  + *uIt;
    //     frag.inject(newMolTag);
    //     newMolTag = mol2 + "z " +*uIt;
    //     frag.inject(newMolTag);
    // }
    // for (alphaIt2 = alphabet.begin();alphaIt2!=alphabet.end();alphaIt2++){
    //     molecule newMol2 = mol2 + "match ";// + *alphaIt2;
    //     frag.inject(newMol2);
    //     newMol2 = mol2 + "z " + "match"; //+ *alphaIt2;
    //     frag.inject(newMol2);

    // }





    frag.interpret("sort.fra");

    frag.run(3000,2000);


    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *series2 = new QtCharts::QLineSeries();
    
    for (int j = 0;j< frag.activeMultisetSize.size();j++){
        // std::cout <<j << " " << frag.activeMultisetSize[j]<<'\n';
        series->append(j,frag.activeMultisetSize[j]);

    }

    for (int j = 0;j< frag.passiveMultisetSize.size();j++){
        // std::cout <<j << " " << frag.passiveMultisetSize[j]<<'\n';
        series2->append(j,frag.passiveMultisetSize[j]);

    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->legend()->hide();
    for (std::vector<int> vec : frag.StackplotVector){
        QtCharts::QLineSeries *series3 = new QtCharts::QLineSeries();
        for (int r = 0;r< vec.size();r++){
            series3->append(r,vec[r]);
        }
        chart->addSeries(series3);
    }


//![2]

//![3]

    // chart->addSeries(series);
    // chart->addSeries(series2);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");
//![3]

//![4]
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![4]


//![5]
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
// //![5]




  

    // return 0;
    return a.exec();
}