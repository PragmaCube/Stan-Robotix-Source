#include "Camera.h"

namespace grip {

Camera::Camera() {
}
/**
* Runs an iteration of the pipeline and updates outputs.
*/
void Camera::Process(cv::Mat& source0){
	//Step Find_Lines0:
	//input
	cv::Mat findLinesInput = source0;
	findLines(findLinesInput, this->findLinesOutput);
	//Step Filter_Lines0:
	//input
	std::vector<Line> filterLinesLines = findLinesOutput;

	// Changer ces valeurs pour changer les valeurs de filtration
	double filterLinesMinLength = 100.0;  // default Double
	double filterLinesAngle[] = {0, 360.0};
	filterLines(filterLinesLines, filterLinesMinLength, filterLinesAngle, this->filterLinesOutput);
}

/**
 * This method is a generated getter for the output of a Find_Lines.
 * @return LinesReport output from Find_Lines.
 */
std::vector<Line>* Camera::GetFindLinesOutput(){
	return &(this->findLinesOutput);
}
/**
 * This method is a generated getter for the output of a Filter_Lines.
 * @return LinesReport output from Filter_Lines.
 */
std::vector<Line>* Camera::GetFilterLinesOutput(){
	return &(this->filterLinesOutput);
}
	/**
	 * Finds all line segments in an image.
	 *
	 * @param input The image on which to perform the find lines.
	 * @param lineList The output where the lines are stored.
	 */
	void Camera::findLines(cv::Mat &input, std::vector<Line> &lineList) {
		cv::Ptr<cv::LineSegmentDetector> lsd = cv::createLineSegmentDetector(LSD_REFINE_STD);
		std::vector<cv::Vec4i> lines;
		lineList.clear();
		if (input.channels() == 1) {
			lsd->detect(input, lines);
		} else {
			// The line detector works on a single channel.
			cv::Mat tmp;
			cv::cvtColor(input, tmp, cv::COLOR_BGR2GRAY);
			lsd->detect(tmp, lines);
		}
		// Store the lines in the LinesReport object
		if (!lines.empty()) {
			for (int i = 0; i < lines.size(); i++) {
				cv::Vec4i line = lines[i];
				lineList.push_back(Line(line[0], line[1], line[2], line[3]));
			}
		}
	}

	/**
	 * Filters out lines that do not meet certain criteria.
	 *
	 * @param inputs The lines that will be filtered.
	 * @param minLength The minimum length of a line to be kept.
	 * @param angle The minimum and maximum angle of a line to be kept.
	 * @param outputs The output lines after the filter.
	 */
	void Camera::filterLines(std::vector<Line> &inputs, double minLength, double angle[], std::vector<Line> &outputs) {
	outputs.clear();
	for (Line line: inputs) {
		if (line.length()>abs(minLength)) {
			if ((line.angle() >= angle[0] && line.angle() <= angle[1]) ||
					(line.angle() + 180.0 >= angle[0] && line.angle() + 180.0 <=angle[1])) {
				outputs.push_back(line);
			}
		}
	}
	}



} // end grip namespace

