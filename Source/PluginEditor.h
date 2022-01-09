/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class WillDDLAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                     public juce::Slider::Listener
{
public:
    WillDDLAudioProcessorEditor (WillDDLAudioProcessor&);
    ~WillDDLAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider *slider) override
    {
        if(slider == &delayTimeSlider)
        {
            audioProcessor.setDelayTime(delayTimeSlider.getValue()) ;
        }
        else if(slider == &feedbackSlider)
        {
            audioProcessor.setFeedback(feedbackSlider.getValue()) ;
        }
        else if(slider == &wetLevelSlider)
        {
            audioProcessor.setWetLevel(wetLevelSlider.getValue()) ;
        }
        audioProcessor.cookVariables();
    };
    
    juce::Slider delayTimeSlider;
    juce::Slider feedbackSlider;
    juce::Slider wetLevelSlider;
    
    juce::Label delayTimeLabel;
    juce::Label feedbackLabel;
    juce::Label wetLevelLabel;
    

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    WillDDLAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WillDDLAudioProcessorEditor)
};
