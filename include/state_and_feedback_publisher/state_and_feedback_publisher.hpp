#ifndef STATE_AND_FEEDBACK_PUBLISHER_HPP_
#define STATE_AND_FEEDBACK_PUBLISHER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "tsukutsuku2_msgs/msg/state_and_feedback.hpp"

class StateAndFeedbackPublisher : public rclcpp::Node
{
public:
    StateAndFeedbackPublisher();

private:
    void PublishStateAndFeedback();

    // パブリッシャー
    rclcpp::Publisher<tsukutsuku2_msgs::msg::StateAndFeedback>::SharedPtr publisher_;

    // タイマー
    rclcpp::TimerBase::SharedPtr timer_;

    // 現在の状態（0と1を交互にパブリッシュするための変数）
    int current_state_;  // この行を追加
};

#endif  // STATE_AND_FEEDBACK_PUBLISHER_HPP_
