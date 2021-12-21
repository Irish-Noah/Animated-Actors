/**
 * @file Rod.h
 * @author Noah O'Bryan
 *
 * Class that creates the rod component for our machine
 */

#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H

#include "Component.h"
#include "PointSource.h"
#include "RodSink.h"
#include "RodSource.h"
#include "PointSink.h"

/**
 * Class that creates the rod component for our machine
 */
class Rod : public Component {
private:
    /// length of the rod
    int mLength;

    /// height of the rod
    int mHeight;

    /// Source for this component
    PointSink mPointSink;

    /// Sink for this component
    std::shared_ptr<RodSink> mRodSink;

    /// Rod source for this component
    std::shared_ptr<RodSource> mRodSource;


public:
    /// Default constructor
    Rod(int length, int height);

    /// Copy constructor (disabled)
    Rod(const Rod &) = delete;

    /// Assignment operator
    void operator=(const Rod &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y) override;

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    PointSink *GetPointSink() { return &mPointSink; }

    void SetPoint(wxPoint point) override;

    /**
     * Set the sink for this rod
     * @param sink Sink to be set
     */
    void SetRodSink(std::shared_ptr<RodSink> sink) { mRodSink = sink; }

    /**
     * Get the length of this rod component
     * @return mLength Length of this rod
     */
    int GetLength() { return mLength; }

    void SetRotation(double rotation) override;

};

#endif //CANADIANEXPERIENCE_ROD_H
