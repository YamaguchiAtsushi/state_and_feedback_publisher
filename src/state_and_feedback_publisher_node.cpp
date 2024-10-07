#include "rclcpp/rclcpp.hpp"
#include "tsukutsuku2_msgs/msg/state_and_feedback.hpp"
#include "state_and_feedback_publisher/state_and_feedback_publisher.hpp"

int main(int argc, char * argv[])
{
    // ROS 2ノードの初期化
    rclcpp::init(argc, argv);

    // ノードのインスタンスを作成
    auto node = std::make_shared<StateAndFeedbackPublisher>();

    // マルチスレッドエグゼキュータを使用してノードをスピン
    rclcpp::spin(node);

    // 終了処理
    rclcpp::shutdown();

    return 0;
}