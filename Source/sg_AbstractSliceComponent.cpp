/*
 This file is part of SpatGRIS.

 Developers: Samuel B�land, Olivier B�langer, Nicolas Masson

 SpatGRIS is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 SpatGRIS is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with SpatGRIS.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "sg_AbstractSliceComponent.hpp"

namespace gris
{
//==============================================================================
AbstractSliceComponent::AbstractSliceComponent(GrisLookAndFeel & lookAndFeel, SmallGrisLookAndFeel & smallLookAndFeel)
    : mLayout(LayoutComponent::Orientation::vertical, false, false, lookAndFeel)
    , mVuMeter(smallLookAndFeel)
    , mMuteSoloComponent(*this, lookAndFeel, smallLookAndFeel)
{
    JUCE_ASSERT_MESSAGE_THREAD;

    addAndMakeVisible(mLayout);
}

//==============================================================================
void AbstractSliceComponent::setState(SliceState const state, bool const soloMode)
{
    JUCE_ASSERT_MESSAGE_THREAD;

    mMuteSoloComponent.setPortState(state);
    mVuMeter.setMuted(soloMode ? state != SliceState::solo : state == SliceState::muted);

    repaint();
}

} // namespace gris