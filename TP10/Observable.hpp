#ifndef _OBSERVABLE_HPP
#define _OBSERVABLE_HPP

#include "Observateur.hpp"
#include <memory>
#include <vector>
#include <algorithm>

template <typename T>
class Observable {
public:
    virtual ~Observable() = default;

    void addObserver(std::shared_ptr<Observateur<T>> observer) {
        observers.push_back(observer);
    }

    void removeObserver(std::shared_ptr<Observateur<T>> observer) {
        observers.erase(std::remove_if(observers.begin(), observers.end(),
            [&observer](const std::weak_ptr<Observateur<T>>& weakObs) {
                return !weakObs.expired() && weakObs.lock() == observer;
            }), observers.end());
    }

protected:
    void notifyAll(const T& data) {
        for (const auto& observer : observers) {
            if (auto obs = observer.lock()) {
                obs->update(data);
            }
        }
    }

private:
    std::vector<std::weak_ptr<Observateur<T>>> observers;
};

#endif
