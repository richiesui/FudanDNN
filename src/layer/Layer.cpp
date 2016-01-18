#include "layer/Layer.h"
#include "util/Matrix.h"


//update error
void Layer::setVisualValue(vector<shared_ptr<Matrix>> visualValue)
{
	this->visualValue = visualValue;
}

//add hidden layer gradient
void Layer::addHiddenGradient(vector<shared_ptr<Matrix>> hiddenGradient)
{
	for (int i = 0; i < hiddenSize; i++){
		for (int row = 0; row < this->hiddenRow; row++){
			for (int column = 0; column < this->hiddenColumn; column++){
				this->hiddenGradient[i]->add(hiddenGradient[i]);
			}
		}
	}
}

vector<shared_ptr<Matrix>> Layer::getVisualValue()
{
	return visualValue;
}

vector<shared_ptr<Matrix>> Layer::getHiddenValue()
{
	return hiddenValue;
}

vector<shared_ptr<Matrix>> Layer::getVisualGradient()
{
	return visualGradient;
}

vector<shared_ptr<Matrix>> Layer::getHiddenGradient()
{
	return hiddenGradient;
}

size_t Layer::getVisualRow()
{
	return this->visualRow;
};

size_t Layer::getVisualColumn()
{
	return this->visualColumn;
};

size_t Layer::getHiddenRow()
{
	return this->hiddenRow;
};

size_t Layer::getHiddenColumn()
{
	return this->hiddenColumn;
};

void Layer::setNetworkName(string networkName)
{
	this->networkname = networkName;
};

// rate for dropout
double Layer::getDropoutRate()
{
	return this->dropoutRate;
};

void Layer::setDropoutRate(double dropoutRate)
{
	this->dropoutRate = dropoutRate;
};

size_t Layer::getVisualSize(){
	return this->visualSize;
}

size_t Layer::getHiddenSize(){
	return this->hiddenSize;
}

void Layer::init(){
	for (size_t v = 0; v < visualSize; v++)
	{
		visualGradient.push_back(instance->allocMatrixUnclean(visualRow, visualColumn));
	}

	for (size_t v = 0; v < hiddenSize; v++)
	{
		hiddenGradient.push_back(instance->allocMatrixUnclean(visualRow, visualColumn));
	}
}



