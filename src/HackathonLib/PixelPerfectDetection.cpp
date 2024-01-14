#include <HackathonLib/PixelPerfectDetection.hpp>
#include <algorithm>


bool pixelPerfectCollision(const sf::Image& mask1, const sf::Vector2f& position1,
                           const sf::Image& mask2, const sf::Vector2f& position2) {
    // Calculate the intersection area
    sf::IntRect intersection;
    if (!getIntersection(mask1, position1, mask2, position2, intersection)) {
        return false;  // No intersection
    }

    // Iterate over the intersection area
    for (int x = intersection.left; x < intersection.left + intersection.width; ++x) {
        for (int y = intersection.top; y < intersection.top + intersection.height; ++y) {
            // Calculate pixel positions relative to each mask
            int pixelX1 = x - static_cast<int>(position1.x);
            int pixelY1 = y - static_cast<int>(position1.y);
            int pixelX2 = x - static_cast<int>(position2.x);
            int pixelY2 = y - static_cast<int>(position2.y);

            // Check if both pixels are non-transparent
            if (mask1.getPixel(pixelX1, pixelY1).a > 0 && mask2.getPixel(pixelX2, pixelY2).a > 0) {
                return true;  // Collision detected
            }
        }
    }

    return false;  // No collision detected
}

bool getIntersection(const sf::Image& mask1, const sf::Vector2f& position1,
                     const sf::Image& mask2, const sf::Vector2f& position2,
                     sf::IntRect& intersection) {
    // Calculate the bounding boxes of the masks
    sf::IntRect bounds1(position1.x, position1.y, mask1.getSize().x, mask1.getSize().y);
    sf::IntRect bounds2(position2.x, position2.y, mask2.getSize().x, mask2.getSize().y);

    // Calculate the intersection of the bounding boxes
    if (bounds1.intersects(bounds2, intersection)) {
        // Clip the intersection to fit within both masks
        intersection.left = std::max(0, std::max(intersection.left, 0));
        intersection.top = std::max(0, std::max(intersection.top, 0));
        intersection.width = std::min(mask1.getSize().x - intersection.left, std::min(mask2.getSize().x - intersection.left, static_cast<unsigned int>(intersection.width)));
        intersection.height = std::min(mask1.getSize().y - intersection.top, std::min(mask2.getSize().y - intersection.top, static_cast<unsigned int>(intersection.height)));

        return true;  // Intersection exists
    }

    return false;  // No intersection
}

bool pixelPerfectCollision(const sf::Image& mask, const sf::Vector2f& position,
                           const sf::FloatRect& boundingBox) {
    // Calculate the intersection area
    sf::IntRect intersection;
    if (!getIntersection(mask, position, boundingBox, intersection)) {
        return false;  // No intersection
    }

    // Iterate over the intersection area
    for (int x = intersection.left; x < intersection.left + intersection.width; ++x) {
        for (int y = intersection.top; y < intersection.top + intersection.height; ++y) {
            // Calculate pixel position relative to the mask
            int pixelX = x - static_cast<int>(position.x);
            int pixelY = y - static_cast<int>(position.y);

            // Check if both pixels are non-transparent
            if (mask.getPixel(pixelX, pixelY).a > 0) {
                return true;  // Collision detected
            }
        }
    }

    return false;  // No collision detected
}

bool getIntersection(const sf::Image& mask, const sf::Vector2f& position,
                     const sf::FloatRect& boundingBox, sf::IntRect& intersection) {
    // Calculate the bounding box of the mask
    sf::IntRect maskBounds(position.x, position.y, mask.getSize().x, mask.getSize().y);
    // Convert boundingBox to sf::IntRect
    sf::IntRect intBoundingBox(
        static_cast<int>(boundingBox.left),
        static_cast<int>(boundingBox.top),
        static_cast<int>(boundingBox.width),
        static_cast<int>(boundingBox.height)
    );
    // Calculate the intersection of the bounding boxes
    if (maskBounds.intersects(intBoundingBox, intersection)) {
        // Clip the intersection to fit within the mask
        intersection.left = std::max(0, std::max(intersection.left, 0));
        intersection.top = std::max(0, std::max(intersection.top, 0));
        intersection.width = std::min(mask.getSize().x - intersection.left, static_cast<unsigned int>(intersection.width));
        intersection.height = std::min(mask.getSize().y - intersection.top, static_cast<unsigned int>(intersection.height));

        return true;  // Intersection exists
    }

    return false;  // No intersection
}