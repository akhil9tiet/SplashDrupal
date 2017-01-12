<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    <div class="content"<?php print $content_attributes; ?>>
        <?php
// We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        //hide($content['field_portfolio_images']);
        $lightboxrel = 'portfolio_' . $nid;
        $portfolio_images = field_get_items('node', $node, 'field_portfolio_images');
        $categories = field_get_items('node', $node, 'field_portfolio_categories');
        $category_name='';
        foreach ($categories as $c=>$category){
            $term = taxonomy_term_load($category['tid']);
            if($c==0){
                $category_name .= $term->name;
            }else{
                $category_name .= ', '.$term->name;
            }
        }
        $first_image = '';
        if ($portfolio_images) {
            foreach ($portfolio_images as $k => $portfolio_image) {
                if ($k == 0) {
                    $first_image = file_create_url($portfolio_image['uri']);
                } else {
                    $image_path = file_create_url($portfolio_image['uri']);
                    print '<a href="' . $image_path . '" rel="lightbox[' . $lightboxrel . ']" style="display:none">&nbsp;</a>';
                }
            }
        }
        ?>
        <a href="<?php print $node_url; ?>">
            <div class="portfolio-image">
                <img src="<?php print $first_image; ?>">
                <div class="mediaholder"></div>
                <div class="portfolio-tools">
                    <div class="info">
                        <?php print $title; ?><br/>
                        <span><?php print $category_name;?></span>
                    </div>
                </div>
            </div>
        </a>
    </div>
    <?php print render($content['links']); ?>
    <?php print render($content['comments']); ?>
</div>